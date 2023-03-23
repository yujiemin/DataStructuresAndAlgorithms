/*
 *  Copyright (c) 2010 ,
 *      Cloud Wu . All rights reserved.
 *
 *      http://www.codingnow.com
 *
 *  Use, modification and distribution are subject to the "New BSD License"
 *  as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.
 */

#ifndef interfacce_gcobject_h
#define interfacce_gcobject_h

#define interface struct

interface i_gcobject {
	virtual ~i_gcobject() {}
	virtual void touch() {}
	virtual void mark() = 0 ;
	virtual void grab() = 0 ;
	virtual void release() = 0 ;

	static void collect();
};

#endif
