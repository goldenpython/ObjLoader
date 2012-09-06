/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __VECTOR2D__H__
#define __VECTOR2D__H__

#include "globalmath.h"
#include <math.h>
#include "matrix2x2.h"

template <class RealNumber>
class CMatrix2x2;

#define MAGNITUDE_VECTOR_2D_POW2(x,y)	((x) * (x) + (y) * (y))
#define MAGNITUDE_VECTOR_2D(x,y)		(sqrt(MAGNITUDE_VECTOR_2D_POW2(x, y)))

template <class RealNumber>
class CVector2D {
	public:
		CVector2D();
		CVector2D(RealNumber x, RealNumber y);
		CVector2D(CVector2D &v);

		CVector2D& operator = (const CVector2D &v);

		CVector2D operator + (const CVector2D &v) const;
		CVector2D& operator += (const CVector2D &v);
		CVector2D& operator + ();

		CVector2D operator - (const CVector2D &v) const;
		CVector2D& operator -= (const CVector2D &v);
		CVector2D operator - () const;

		CVector2D operator * (const RealNumber v) const;
		CVector2D& operator *= (const RealNumber v);

		CVector2D operator * (const CMatrix2x2<RealNumber> &m) const;
		CVector2D& operator *= (const CMatrix2x2<RealNumber> &m); 

		CVector2D operator / (const RealNumber v);
		CVector2D& operator /= (const RealNumber v);

		bool operator == (const CVector2D &v) const;
		bool operator != (const CVector2D &v) const;

		RealNumber  Magnitude() const;
		RealNumber Magnitude_Pow2() const;
		void Normalize();

		RealNumber DotProduct(const CVector2D *v);
		static RealNumber DotProduct(const CVector2D *v1, const CVector2D *v2);

	public:
		union {
			RealNumber M[2];
			struct {
				RealNumber x, y;
			};
		};
};

#include "vector2D_inline.h"

#endif	//__VECTOR2D__H__
