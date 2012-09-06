/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __POINT_2D__H__
#define __POINT_2D__H__

#include <math.h>
#include "globalmath.h"
#include "polar2D.h"
#include "distance.h"

template <class RealNumber>
class CPolar2D;

template <class RealNumber>
class CPoint2D {
	public:
		CPoint2D();
		CPoint2D(RealNumber x, RealNumber y);
		CPoint2D(CPoint2D &point);
		CPoint2D(CPolar2D<RealNumber> &point);

		//distance
		RealNumber DistanceFromOrigin() const;
		RealNumber DistanceFromOriginPow2() const;

		RealNumber Distance(const CPoint2D &point) const;
		RealNumber DistancePow2(const CPoint2D &point) const;

		CPoint2D& operator = (const CPoint2D &p);

		bool operator == (const CPoint2D &p) const;
		bool operator != (const CPoint2D &p) const;

	public:
		union {
			RealNumber M[2];
			struct {
				RealNumber x, y;
			};
		};
};

#include "point2D_inline.h"

#endif //__POINT_2D__H__