/*
 *  Copyright (c) 2010 ,
 *      Cloud Wu . All rights reserved.
 *
 *      http://www.codingnow.com
 *
 *  Use, modification and distribution are subject to the "New BSD License"
 *  as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.
 */

#include "i_gcholder.h"
#include "gcobject.h"
#include <vector>
#include <algorithm>
#include <cassert>

class gcholder : public virtual i_gcholder, virtual gcobject {
	std::vector<i_gcobject *> hold_set;
	std::vector<i_gcobject *> unhold_set;
	bool set_changed;
	bool hold_set_sorted;
	bool unhold_set_sorted;
	void combine_set();
	virtual void touch();
	virtual void hold(i_gcobject *obj) {
		hold_set.push_back(obj);
		hold_set_sorted = false;
		set_changed = true;
	}
	virtual void unhold(i_gcobject *obj) {
		unhold_set.push_back(obj);
		unhold_set_sorted = false;
		set_changed = true;
	}
	struct f_mark {
		void operator() (i_gcobject *obj) {
			obj->mark();
		}
	};
public:
	gcholder() : 
		set_changed(false), 
		hold_set_sorted(true) , 
		unhold_set_sorted(true) {}
};

void 
gcholder::combine_set()
{
	if (!hold_set_sorted) {
		std::sort(hold_set.begin(),hold_set.end());
		hold_set_sorted = true;
	}
	if (!unhold_set_sorted) {
		std::sort(unhold_set.begin(),unhold_set.end());
		unhold_set_sorted = true;
	}
	if (!unhold_set.empty()) {
		std::vector<i_gcobject *>::iterator iter1 = hold_set.begin();
		std::vector<i_gcobject *>::iterator iter2 = unhold_set.begin();
		while (iter1 != hold_set.end() && iter2 != unhold_set.end()) {
			if (*iter1 == *iter2) {
				*iter1 = NULL;
				++iter1;
				++iter2;
			}
			else {
				assert(*iter1 < *iter2);
				++iter1;
			}
		}
		i_gcobject * null = NULL;
		hold_set.erase(std::remove(hold_set.begin(),hold_set.end(),null) , hold_set.end());
		unhold_set.clear();
	}
}

void 
gcholder::touch()
{
	if (set_changed) {
		combine_set();
		set_changed = false;
	}

	std::for_each(hold_set.begin(), hold_set.end(), f_mark());
}

i_gcholder * 
i_gcholder::create()
{
	return new gcholder;
}


