/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __MATRIX2X2__H__
#define __MATRIX2X2__H__

#include "globalmath.h"
#include "vector2D.h"

template <class RealNumber>
class CVector2D;

template <class RealNumber>
class CMatrix2x2 {
	public:
		CMatrix2x2(); 
		CMatrix2x2(CVector2D<RealNumber> &l1, CVector2D<RealNumber> &l2);
		CMatrix2x2(RealNumber m11, RealNumber m12, RealNumber m21, RealNumber m22);
		CMatrix2x2(CMatrix2x2 &m);

		CMatrix2x2& operator = (const CMatrix2x2 &m);

		CMatrix2x2& operator + ();
		CMatrix2x2 operator + (const CMatrix2x2 &m) const;
		CMatrix2x2& operator += (const CMatrix2x2 &m);

		CMatrix2x2 operator - () const;
		CMatrix2x2 operator - (const CMatrix2x2 &m) const;
		CMatrix2x2& operator -= (const CMatrix2x2 &m);

		CMatrix2x2 operator * (const RealNumber v) const;
		CMatrix2x2& operator *= (const RealNumber v);
		CMatrix2x2 operator * (const CMatrix2x2 &m) const;
		CMatrix2x2& operator *= (const CMatrix2x2 &m);

		CMatrix2x2 operator / (const RealNumber v) const;
		CMatrix2x2& operator /= (const RealNumber v);

		RealNumber Determinant();
		CMatrix2x2 Transpose();
		static CMatrix2x2* FillTranspose(CMatrix2x2 *m);

		const static CMatrix2x2 Identity;
		static CMatrix2x2* FillIdentity(CMatrix2x2 *out);

		const static CMatrix2x2 Zero;
		static CMatrix2x2* FillZeroMatrix(CMatrix2x2 *out);

		static CMatrix2x2* FillMatrixRotation(CMatrix2x2 *out, RealNumber angle);
		static CMatrix2x2 MatrixRotation(RealNumber angle);

	public:
		union {
			RealNumber M[2][2];
			struct {
				RealNumber M11, M12;
				RealNumber M21, M22;
			};
		};
};

#include "matrix2x2_inline.h"

#endif //__MATRIX2X2__H__