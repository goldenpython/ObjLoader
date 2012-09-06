/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __POLAR_2D__H
#define __POLAR_2D__H

#include <math.h>
#include "globalmath.h"
#include "point2D.h"
#include "distance.h"

template <class RealNumber>
class CPoint2D;

template <class RealNumber>
class CPolar2D {
	public:
		CPolar2D();
		CPolar2D(RealNumber d);
		CPolar2D(RealNumber d, RealNumber angle);
 		CPolar2D(CPoint2D<RealNumber> &point);

		CPolar2D & operator = (const CPolar2D &p);

	public:
		RealNumber d, angle;
};

#include "polar2D_inline.h"

#endif //__POLAR_2D__H