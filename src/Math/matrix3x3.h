/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __MATRIX3X3__H__
#define __MATRIX3X3__H__

#include "globalmath.h"
#include "vector3D.h"

template <class RealNumber>
class CVector3D;

template <class RealNumber>
class CMatrix3x3 {
	public:
		CMatrix3x3();
		CMatrix3x3(CVector3D<RealNumber> &l1, CVector3D<RealNumber> &l2, CVector3D<RealNumber> &l3);
		CMatrix3x3(RealNumber m11, RealNumber m12, RealNumber m13, RealNumber m21, RealNumber m22, RealNumber m23, RealNumber m31, RealNumber m32, RealNumber m33);
		CMatrix3x3(CMatrix3x3 &m);

		CMatrix3x3& operator = (const CMatrix3x3 &m);

		CMatrix3x3& operator + ();
		CMatrix3x3 operator + (const CMatrix3x3 &m) const;
		CMatrix3x3& operator += (const CMatrix3x3 &m);

		CMatrix3x3 operator - () const;
		CMatrix3x3 operator - (const CMatrix3x3 &m) const;
		CMatrix3x3& operator -= (const CMatrix3x3 &m);

		CMatrix3x3 operator * (const RealNumber v) const;
		CMatrix3x3& operator *= (const RealNumber v);
		CMatrix3x3 operator * (const CMatrix3x3 &m) const; 
		CMatrix3x3& operator *= (const CMatrix3x3 &m);

		CMatrix3x3 operator / (const RealNumber v) const;
		CMatrix3x3& operator /= (const RealNumber v);

		RealNumber Determinant() const;

		CMatrix3x3 Transpose() const;
		static CMatrix3x3* FillTranspose(CMatrix3x3 *m);

		const static CMatrix3x3 Identity;
		static CMatrix3x3* FillIdentity(CMatrix3x3 *out);

		const static CMatrix3x3 Zero;
		static CMatrix3x3* FillZero(CMatrix3x3 *out);

		static CMatrix3x3* FillMatrixRotationOX(const RealNumber fAngle, CMatrix3x3 *poMatrixResult);
		static CMatrix3x3* FillMatrixRotationOY(const RealNumber fAngle, CMatrix3x3 *poMatrixResult);
		static CMatrix3x3* FillMatrixRotationOZ(const RealNumber fAngle, CMatrix3x3 *poMatrixResult);

		static CMatrix3x3* FillScaleMatrix(const RealNumber fSx, const RealNumber fSy, const RealNumber fSz, CMatrix3x3 *poMatrixResult);

	public:
		union {
			RealNumber M[3][3];
			struct {
				RealNumber M11, M12, M13;
				RealNumber M21, M22, M23;
				RealNumber M31, M32, M33;
			};
		};
};

#include "matrix3x3_inline.h"

#endif //__MATRIX3X3__H__