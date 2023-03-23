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
#include "i_gcholder.h"

#include <vector>
#include <algorithm>

static bool gc_trigger;
static std::vector<gcobject *> gc_pool;
static i_gcholder * gc_root = i_gcholder::create();

struct gcobject::f_unmarked {
	bool operator() (gcobject * value) {
		bool unmarked = value->marked != gc_trigger;
		if (unmarked) {
			delete value;
		}
		return unmarked;
	}
};

gcobject::gcobject() : marked(!gc_trigger) 
{
	gc_pool.push_back(this);
}

void 
gcobject::mark() 
{
	if (marked != gc_trigger) {
		marked = gc_trigger;
		touch();
	}
}

void 
gcobject::grab()
{
	gc_root->hold(this);
}

void 
gcobject::release()
{
	gc_root->unhold(this);
}

void 
i_gcobject::collect() 
{
	gc_root->mark();

	gc_pool.erase(remove_if(gc_pool.begin(), gc_pool.end() , gcobject::f_unmarked()), gc_pool.end());

	gc_trigger = !gc_trigger;
}
