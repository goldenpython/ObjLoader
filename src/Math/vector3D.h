/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __VECTOR3D__H__
#define __VECTOR3D__H__

#include <math.h>
#include "globalmath.h"
#include "vector2D.h"
#include "matrix3x3.h"

template <class RealNumber>
class CVector2D;

template <class RealNumber>
class CMatrix3x3;

#define MAGNITUDE_VECTOR_3D_POW2(x,y,z)	((x) * (x) + (y) * (y) + (z) * (z))
#define MAGNITUDE_VECTOR_3D(x,y,z)		(sqrt(MAGNITUDE_VECTOR_3D_POW2(x, y, z)))

template <class RealNumber>
class CVector3D {
	public:
		CVector3D();
		CVector3D(RealNumber x, RealNumber y, RealNumber z);
		CVector3D(CVector3D &v);
		CVector3D(CVector2D<RealNumber> &v);

		CVector3D& operator = (const CVector3D &v);

		CVector3D operator + (const CVector3D &v) const;
		CVector3D operator += (const CVector3D &v);
		CVector3D& operator + ();

		CVector3D operator - (const CVector3D &v) const;
		CVector3D operator -= (const CVector3D &v);
		CVector3D operator - () const;

		CVector3D operator * (const RealNumber v) const;
		CVector3D& operator *= (const RealNumber v);

		CVector3D operator * (const CMatrix3x3<RealNumber> &m) const;
		CVector3D& operator *= (const CMatrix3x3<RealNumber> &m);  

		CVector3D operator / (const RealNumber v) const;
		CVector3D& operator /= (const RealNumber v);

		bool operator == (const CVector3D &v);
		bool operator != (const CVector3D &v);

		RealNumber Magnitude() const;
		RealNumber Magnitude_Pow2() const;
		void Normalize();

		RealNumber DotProduct(const CVector3D *v) const;
		static RealNumber DotProduct(const CVector3D *v1, const CVector3D *v2);

	public:
		union {
			RealNumber M[3];
			struct {
				RealNumber x, y, z;
			};
		};
};

#include "vector3D_inline.h"

#endif	//__VECTOR3D__H__
