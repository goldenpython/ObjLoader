/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __MATRIX4X4__H__
#define __MATRIX4X4__H__

#include "globalmath.h"
#include "vector4D.h"

template <class RealNumber>
class CVector4D;

template <class RealNumber>
class CMatrix4x4 {
public:
	CMatrix4x4();
	CMatrix4x4(CVector4D<RealNumber> &l1, CVector4D<RealNumber> &l2, CVector4D<RealNumber> &l3, CVector4D<RealNumber> &l4);
	CMatrix4x4(
			RealNumber m11, RealNumber m12, RealNumber m13, RealNumber m14, 
			RealNumber m21, RealNumber m22, RealNumber m23, RealNumber m24,
			RealNumber m31, RealNumber m32, RealNumber m33, RealNumber m34, 
			RealNumber m41, RealNumber m42, RealNumber m43, RealNumber m44
	);

	CMatrix4x4(CMatrix4x4 &m);

	CMatrix4x4& operator = (const CMatrix4x4 &m);

	CMatrix4x4& operator + ();
	CMatrix4x4 operator + (const CMatrix4x4 &m) const;
	CMatrix4x4& operator += (const CMatrix4x4 &m);

	CMatrix4x4 operator - () const;
	CMatrix4x4 operator - (const CMatrix4x4 &m) const;
	CMatrix4x4& operator -= (const CMatrix4x4 &m);

	CMatrix4x4 operator * (const RealNumber v) const;
	CMatrix4x4& operator *= (const RealNumber v);
	CMatrix4x4 operator * (const CMatrix4x4 &m) const; 
	CMatrix4x4& operator *= (const CMatrix4x4 &m);

	CMatrix4x4 operator / (const RealNumber v) const;
	CMatrix4x4& operator /= (const RealNumber v);

	RealNumber Determinant() const;

	CMatrix4x4 Transpose() const;
	CMatrix4x4* FillTranspose(CMatrix4x4 *m);

	const static CMatrix4x4 Identity;
	static CMatrix4x4* FillIdentity(CMatrix4x4 *out);

	const static CMatrix4x4 Zero;
	static CMatrix4x4* FillZero(CMatrix4x4 *out);

	static CMatrix4x4* FillMatrixRotationOX(const RealNumber fAngle, CMatrix4x4 *poMatrixResult);
	static CMatrix4x4* FillMatrixRotationOY(const RealNumber fAngle, CMatrix4x4 *poMatrixResult);
	static CMatrix4x4* FillMatrixRotationOZ(const RealNumber fAngle, CMatrix4x4 *poMatrixResult);

	static CMatrix4x4* FillMatrixTranslation(const RealNumber fTx, const RealNumber fTy,  const RealNumber fTz, CMatrix4x4 *poMatrixresult);
	static CMatrix4x4* FillMatrixScale(const RealNumber fSx, const RealNumber fSy,  const RealNumber fSz, CMatrix4x4 *poMatrixresult);

public:
	union {
		RealNumber M[4][4];
		struct {
			RealNumber M11, M12, M13, M14;
			RealNumber M21, M22, M23, M24;
			RealNumber M31, M32, M33, M34;
			RealNumber M41, M42, M43, M44;
		};
	};
};

#include "matrix4x4_inline.h"

#endif //__MATRIX4X4__H__