/*
 *  Copyright (c) 2010 ,
 *      Cloud Wu . All rights reserved.
 *
 *      http://www.codingnow.com
 *
 *  Use, modification and distribution are subject to the "New BSD License"
 *  as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.
 */

#ifndef interfacce_gcholder_h
#define interfacce_gcholder_h

#include "i_gcobject.h"

interface i_gcholder : virtual i_gcobject {
	virtual void hold(i_gcobject *) = 0;
	virtual void unhold(i_gcobject *) = 0;
	
	static i_gcholder * create();
};

#endif
