/*
 *  Copyright (c) 2010 ,
 *      Cloud Wu . All rights reserved.
 *
 *      http://www.codingnow.com
 *
 *  Use, modification and distribution are subject to the "New BSD License"
 *  as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.
 */

#include "gcobject.h"

#include <cstdio>
#include <set>
#include <algorithm>

interface i_tree : virtual i_gcobject {
	virtual void link(i_tree *p) = 0;

	static i_tree * create();
};

class tree : public virtual i_tree , virtual gcobject {
	tree *parent;
	std::multiset<tree *> children;

	struct f_mark {
		void operator() (tree *node) {
			node->mark();
		}
	};

	virtual void touch() {
		if (parent)
			parent->mark();

		std::for_each(children.begin(), children.end(), f_mark());
	}

	void unlink();

	virtual void link(i_tree *parent);
public:
	tree() : parent(NULL) {
		printf("create node %p\n",this);
	}
	~tree() {
		printf("release node %p\n",this);
	}
};

void
tree::unlink()
{
	if (parent) {
		parent->children.erase(this);

		parent = NULL;
	}
}

void 
tree::link(i_tree *p)
{
	unlink();
	if (p) {
		tree * cp = dynamic_cast<tree *>(p);
		cp->children.insert(this);
		parent = cp;
	}
}

i_tree *
i_tree::create()
{
	return new tree;
}

int 
main()
{
	i_tree *root = i_tree::create();

	root->grab();

	i_tree *node;

	node = i_tree::create();
	node->link(root);

	node = i_tree::create();
	node->link(root);

	i_gcobject::collect();

	printf("collected\n");
	node->link(NULL);

	i_gcobject::collect();

	printf("finalize\n");

	root->release();

	i_gcobject::collect();

	return 0;
}
