/*
 *  Copyright (c) 2010 ,
 *      Cloud Wu . All rights reserved.
 *
 *      http://www.codingnow.com
 *
 *  Use, modification and distribution are subject to the "New BSD License"
 *  as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.
 */

#ifndef gc_object_h
#define gc_object_h

#include "i_gcobject.h"

class gcobject : virtual i_gcobject {
	bool marked;
public:
	gcobject();
	virtual void mark();
	virtual void grab();
	virtual void release();
	struct f_unmarked;
};

#endif
