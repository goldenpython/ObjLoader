/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __VECTOR4D__H__
#define __VECTOR4D__H__

#include <math.h>
#include "globalmath.h"
#include "vector2D.h"
#include "matrix3x3.h"

template <class RealNumber>
class CVector2D;

template <class RealNumber>
class CVector3D;

template <class RealNumber>
class CMatrix4x4;

#define MAGNITUDE_VECTOR_4D_POW2(x,y,z,w)	((x) * (x) + (y) * (y) + (z) * (z) + (w) * (w))
#define MAGNITUDE_VECTOR_4D(x,y,z,w)		(sqrt(MAGNITUDE_VECTOR_4D_POW2(x, y, z, w)))

template <class RealNumber>
class CVector4D {
public:
	CVector4D();
	CVector4D(RealNumber x, RealNumber y, RealNumber z, RealNumber w);
	CVector4D(CVector4D &v);
	CVector4D(CVector3D<RealNumber> &v);
	CVector4D(CVector2D<RealNumber> &v);

	CVector4D& operator = (const CVector4D &v);

	CVector4D operator + (const CVector4D &v) const;
	CVector4D operator += (const CVector4D &v);
	CVector4D& operator + ();

	CVector4D operator - (const CVector4D &v) const;
	CVector4D operator -= (const CVector4D &v);
	CVector4D operator - () const;

	CVector4D operator * (const RealNumber v) const;
	CVector4D& operator *= (const RealNumber v);

	CVector4D operator * (const CMatrix4x4<RealNumber> &m) const;
	CVector4D& operator *= (const CMatrix4x4<RealNumber> &m);  

	CVector4D operator / (const RealNumber v) const;
	CVector4D& operator /= (const RealNumber v);

	bool operator == (const CVector4D &v);
	bool operator != (const CVector4D &v);

	RealNumber Magnitude() const;
	RealNumber Magnitude_Pow2() const;
	void Normalize();

	RealNumber DotProduct(const CVector4D *v) const;
	static RealNumber DotProduct(const CVector4D *v1, const CVector4D *v2);

public:
	union {
		RealNumber M[4];
		struct {
			RealNumber x, y, z, w;
		};
	};
};

#include "vector4D_inline.h"

#endif	//__VECTOR4D__H__
