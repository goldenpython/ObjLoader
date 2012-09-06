/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>::CMatrix4x4() { 
	M11 = M12 = M13 = M14 = M21 = M22 = M23 = M24 = M31 = M32 = M33 = M34 = M41 = M42 = M43 = M44 = 0.0f; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>::CMatrix4x4(
	RealNumber m11, RealNumber m12, RealNumber m13, RealNumber m14,
	RealNumber m21, RealNumber m22, RealNumber m23, RealNumber m24,
	RealNumber m31, RealNumber m32, RealNumber m33, RealNumber m34,
	RealNumber m41, RealNumber m42, RealNumber m43, RealNumber m44
) { 
	M11 = m11, M12 = m12, M13 = m13, M14 = m14,
	M21 = m21, M22 = m22, M23 = m23, M24 = m24, 
	M31 = m31, M32 = m32, M33 = m33; M34 = m34,
	M41 = m41, M42 = m42, M43 = m43; M44 = m44;
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>::CMatrix4x4(CMatrix4x4 &m) { 
	M11 = m.M11, M12 = m.M12, M13 = m.M13, M14 = m.M14,
	M21 = m.M21, M22 = m.M22, M23 = m.M23, M24 = m.M24,
	M31 = m.M31, M32 = m.M32, M33 = m.M33, M34 = m.M34,
	M41 = m.M41, M42 = m.M42, M43 = m.M43, M44 = m.M44;
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>& CMatrix4x4<RealNumber>::operator = (const CMatrix4x4 &m) { 
	M11 = m.M11, M12 = m.M12, M13 = m.M13, M14 = m.M14,
	M21 = m.M21, M22 = m.M22, M23 = m.M23, M24 = m.M24,
	M31 = m.M31, M32 = m.M32, M33 = m.M33, M34 = m.M34,
	M41 = m.M41, M42 = m.M42, M43 = m.M43, M44 = m.M44;

	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>& CMatrix4x4<RealNumber>::operator + () { 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber> CMatrix4x4<RealNumber>::operator + (const CMatrix4x4 &m) const { 
	return CMatrix4x4(
		M11 + m.M11, M12 + m.M12, M13 + m.M13, M14 + m.M14,
		M21 + m.M21, M22 + m.M22, M23 + m.M23, M24 + m.M24, 
		M31 + m.M31, M32 + m.M32, M33 + m.M33, M34 + m.M34,
		M41 + m.M41, M42 + m.M42, M43 + m.M43, M44 + m.M44
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>& CMatrix4x4<RealNumber>::operator += (const CMatrix4x4 &m) { 
	M11 += m.M11, M12 += m.M12, M13 += m.M13, M14 += m.M14,
	M21 += m.M21, M22 += m.M22, M23 += m.M23, M23 += m.M24,
	M31 += m.M31, M32 += m.M32, M33 += m.M33, M34 += m.M34,
	M41 += m.M41, M42 += m.M42, M43 += m.M43, M44 += m.M44;

	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber> CMatrix4x4<RealNumber>::operator - () const { 
	return CMatrix4x4(
		-M11, -M12, -M13, -M14,
		-M21, -M22, -M23, -M24, 
		-M31, -M32, -M33, -M34,
		-M41, -M42, -M43, -M44
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber> CMatrix4x4<RealNumber>::operator - (const CMatrix4x4 &m) const { 
	return CMatrix4x4(
		M11 - m.M11, M12 - m.M12, M13 - m.M13, M14 - m.M14,
		M21 - m.M21, M22 - m.M22, M23 - m.M23, M24 - m.M24,
		M31 - m.M31, M32 - m.M32, M33 - m.M33, M34 - m.M34,
		M41 - m.M41, M42 - m.M42, M43 - m.M43, M44 - m.M44
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>& CMatrix4x4<RealNumber>::operator -= (const CMatrix4x4 &m) { 
	M11 -= m.M11, M12 -= m.M12, M13 -= m.M13, M14 -= m.M14,
	M21 -= m.M21, M22 -= m.M22, M23 -= m.M23, M24 -= m.M24, 
	M31 -= m.M31, M32 -= m.M32, M33 -= m.M33, M34 -= m.M34,
	M41 -= m.M41, M42 -= m.M42, M43 -= m.M43, M44 -= m.M44;

	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber> CMatrix4x4<RealNumber>::operator * (const RealNumber v) const { 
	return CMatrix4x4(
		M11 * v, M12 * v, M13 * v, M14 * v,
		M21 * v, M22 * v, M23 * v, M24 * v,
		M31 * v, M32 * v, M33 * v, M34 * v,
		M41 * v, M42 * v, M43 * v, M44 * v
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>& CMatrix4x4<RealNumber>::operator *= (const RealNumber v) { 
	M11 *= v, M12 *= v, M13 *= v, M14 *= v,
	M21 *= v, M22 *= v, M23 *= v, M24 *= v,
	M31 *= v, M32 *= v, M33 *= v, M34 *= v,
	M41 *= v, M42 *= v, M43 *= v, M44 *= v;

	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber> CMatrix4x4<RealNumber>::operator * (const CMatrix4x4 &m) const {
	return CMatrix4x4(
		M11 * m.M11 + M12 * m.M21 + M13 * m.M31 + M14 * m.M41,
		M11 * m.M12 + M12 * m.M22 + M13 * m.M32 + M14 * m.M42,
		M11 * m.M13 + M12 * m.M23 + M13 * m.M33 + M14 * m.M43,
		M11 * m.M14 + M12 * m.M24 + M13 * m.M34 + M14 * m.M44,

		M21 * m.M11 + M22 * m.M21 + M23 * m.M31 + M24 * m.M41,
		M21 * m.M12 + M22 * m.M22 + M23 * m.M32 + M24 * m.M42,
		M21 * m.M13 + M22 * m.M23 + M23 * m.M33 + M24 * m.M43,
		M21 * m.M14 + M22 * m.M24 + M23 * m.M34 + M24 * m.M44,

		M31 * m.M11 + M32 * m.M21 + M33 * m.M31 + M34 * m.M41,
		M31 * m.M12 + M32 * m.M22 + M33 * m.M32 + M34 * m.M42,
		M31 * m.M13 + M32 * m.M23 + M33 * m.M33 + M34 * m.M43,
		M31 * m.M14 + M32 * m.M24 + M33 * m.M34 + M34 * m.M44,

		M41 * m.M11 + M42 * m.M21 + M43 * m.M31 + M44 * m.M41,
		M41 * m.M12 + M42 * m.M22 + M43 * m.M32 + M44 * m.M42,
		M41 * m.M13 + M42 * m.M23 + M43 * m.M33 + M44 * m.M43,
		M41 * m.M14 + M42 * m.M24 + M43 * m.M34 + M44 * m.M44
	);
};

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>& CMatrix4x4<RealNumber>::operator *= (const CMatrix4x4 &m) {
	RealNumber a11 = M11 * m.M11 + M12 * m.M21 + M13 * m.M31 + M14 * m.M41;
	RealNumber a12 = M11 * m.M12 + M12 * m.M22 + M13 * m.M32 + M14 * m.M42;
	RealNumber a13 = M11 * m.M13 + M12 * m.M23 + M13 * m.M33 + M14 * m.M43;
	RealNumber a14 = M11 * m.M14 + M12 * m.M24 + M13 * m.M34 + M14 * m.M44;

	RealNumber a21 = M21 * m.M11 + M22 * m.M21 + M23 * m.M31 + M24 * m.M41;
	RealNumber a22 = M21 * m.M12 + M22 * m.M22 + M23 * m.M32 + M24 * m.M42;
	RealNumber a23 = M21 * m.M13 + M22 * m.M23 + M23 * m.M33 + M24 * m.M43;
	RealNumber a24 = M21 * m.M14 + M22 * m.M24 + M23 * m.M34 + M24 * m.M44;

	RealNumber a31 = M31 * m.M11 + M32 * m.M21 + M33 * m.M31 + M34 * m.M41;
	RealNumber a32 = M31 * m.M12 + M32 * m.M22 + M33 * m.M32 + M34 * m.M42;
	RealNumber a33 = M31 * m.M13 + M32 * m.M23 + M33 * m.M33 + M34 * m.M43;
	RealNumber a34 = M31 * m.M14 + M32 * m.M24 + M33 * m.M34 + M34 * m.M44;

	RealNumber a41 = M41 * m.M11 + M42 * m.M21 + M43 * m.M31 + M44 * m.M41;
	RealNumber a42 = M41 * m.M12 + M42 * m.M22 + M43 * m.M32 + M44 * m.M42;
	RealNumber a43 = M41 * m.M13 + M42 * m.M23 + M43 * m.M33 + M44 * m.M43;
	RealNumber a44 = M41 * m.M14 + M42 * m.M24 + M43 * m.M34 + M44 * m.M44;

	M11 = a11;
	M12 = a12;
	M13 = a13;
	M14 = a14;

	M21 = a21;
	M22 = a22;
	M23 = a23;
	M24 = a24;

	M31 = a31;
	M32 = a32;
	M33 = a33;
	M34 = a34;

	M41 = a41;
	M42 = a42;
	M43 = a43;
	M44 = a44;

	return *this;
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber> CMatrix4x4<RealNumber>::operator / (const RealNumber v) const { 
	return CMatrix4x4(
		M11 / v, M12 / v, M13 / v, M14 / v,
		M21 / v, M22 / v, M23 / v, M24 / v,
		M31 / v, M32 / v, M33 / v, M34 / v,
		M41 / v, M42 / v, M43 / v, M44 / v
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>& CMatrix4x4<RealNumber>::operator /= (const RealNumber v) { 
	M11 /= v, M12 /= v, M13 /= v, M14 /= v,
	M21 /= v, M22 /= v, M23 /= v, M24 /= v,
	M31 /= v, M32 /= v, M33 /= v, M34 /= v,
	M41 /= v, M42 /= v, M43 /= v, M44 /= v;

	return *this; 
}

template <class RealNumber>
MATH_INLINE RealNumber CMatrix4x4<RealNumber>::Determinant() const { 
	//to do
	return 0 ;//M11 * M22 * M33 + M21 * M32 * M13 + M31 * M12 * M23
		//- M13 * M22 * M31 - M23 * M32 * M11 - M33 * M12 * M21; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber> CMatrix4x4<RealNumber>::Transpose() const { 
	return CMatrix4x4(
		M11, M21, M31, M41, 
		M12, M22, M32, M42,
		M13, M23, M33, M43,
		M14, M24, M34, M44
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>* CMatrix4x4<RealNumber>::FillTranspose(CMatrix4x4 *m) { 
	m->M11 = M11, m->M12 = M21, m->M13 = M31, m->M14 = M41,
	m->M21 = M12, m->M22 = M22, m->M23 = M32, m->M24 = M42,
	m->M31 = M13, m->M32 = M23, m->M33 = M33, m->M34 = M43,
	m->M41 = M14, m->M42 = M24, m->M43 = M34, m->M44 = M44;

	return m; 
};

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>* CMatrix4x4<RealNumber>::FillIdentity(CMatrix4x4 *out) { 
	out->M11 = 1.0f, out->M12 = 0.0f, out->M13 = 0.0f, out->M14 = 0.0f,
	out->M21 = 0.0f, out->M22 = 1.0f, out->M23 = 0.0f, out->M24 = 0.0f,
	out->M31 = 0.0f, out->M32 = 0.0f, out->M33 = 1.0f, out->M34 = 0.0f,
	out->M41 = 0.0f, out->M42 = 0.0f, out->M43 = 0.0f, out->M44 = 1.0f;

	return out; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>* CMatrix4x4<RealNumber>::FillZero(CMatrix4x4 *out) { 
	out->M11 = 0.0f, out->M12 = 0.0f, out->M13 = 0.0f, out->M14 = 0.0f,
	out->M21 = 0.0f, out->M22 = 0.0f, out->M23 = 0.0f, out->M24 = 0.0f,
	out->M31 = 0.0f, out->M32 = 0.0f, out->M33 = 0.0f, out->M34 = 0.0f,
	out->M41 = 0.0f, out->M42 = 0.0f, out->M43 = 0.0f, out->M44 = 0.0f;

	return out; 
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>::CMatrix4x4(
		CVector4D<RealNumber> &l1, 
		CVector4D<RealNumber> &l2, 
		CVector4D<RealNumber> &l3, 
		CVector4D<RealNumber> &l4) { 

	M11 = l1.x; M12 = l1.y; M13 = l1.z; M14 = l1.w;
	M21 = l2.x; M22 = l2.y; M23 = l2.z; M24 = l2.w;
	M31 = l3.x; M32 = l3.y; M33 = l3.z; M34 = l3.w;
	M41 = l4.x; M42 = l4.y; M43 = l4.z; M44 = l4.w;
}

template <class RealNumber>
CMatrix4x4<RealNumber>* CMatrix4x4<RealNumber>::FillMatrixRotationOX(const RealNumber fAngle, CMatrix4x4 *poMatrixResult) {
	poMatrixResult->M11 = 1.0f;
	poMatrixResult->M12 = 0.0f;
	poMatrixResult->M13 = 0.0f;
	poMatrixResult->M14 = 0.0f;

	poMatrixResult->M21 = 0.0f;
	poMatrixResult->M22 = cos(fAngle);
	poMatrixResult->M23 = sin(fAngle);
	poMatrixResult->M24 = 0.0f;

	poMatrixResult->M31 = 0.0f;
	poMatrixResult->M32 = -sin(fAngle);
	poMatrixResult->M33 = cos(fAngle);
	poMatrixResult->M34 = 0.0f;

	poMatrixResult->M41 = 0.0f;
	poMatrixResult->M42 = 0.0f;
	poMatrixResult->M43 = 0.0f;
	poMatrixResult->M44 = 1.0f;

	return poMatrixResult;
}

template <class RealNumber>
CMatrix4x4<RealNumber>* CMatrix4x4<RealNumber>::FillMatrixRotationOY(const RealNumber fAngle, CMatrix4x4 *poMatrixResult) {
	poMatrixResult->M11 = cos(fAngle);
	poMatrixResult->M12 = 0.0f;
	poMatrixResult->M13 = -sin(fAngle);
	poMatrixResult->M14 = 0.0f;

	poMatrixResult->M21 = 0.0f;
	poMatrixResult->M22 = 1.0f;
	poMatrixResult->M23 = 0.0f;
	poMatrixResult->M24 = 0.0f;

	poMatrixResult->M31 = sin(fAngle);
	poMatrixResult->M32 = 0.0f;
	poMatrixResult->M33 = cos(fAngle);
	poMatrixResult->M34 = 0.0f;

	poMatrixResult->M41 = 0.0f;
	poMatrixResult->M42 = 0.0f;
	poMatrixResult->M43 = 0.0f;
	poMatrixResult->M44 = 1.0f;

	return poMatrixResult;
}

template <class RealNumber>
CMatrix4x4<RealNumber>* CMatrix4x4<RealNumber>::FillMatrixRotationOZ(const RealNumber fAngle, CMatrix4x4 *poMatrixResult) {
	poMatrixResult->M11 = cos(fAngle);
	poMatrixResult->M12 = sin(fAngle);
	poMatrixResult->M13 = 0.0f;
	poMatrixResult->M14 = 0.0f;

	poMatrixResult->M21 = -sin(fAngle);
	poMatrixResult->M22 = cos(fAngle);
	poMatrixResult->M23 = 0.f;
	poMatrixResult->M24 = 0.f;

	poMatrixResult->M31 = 0.0f;
	poMatrixResult->M32 = 0.0f;
	poMatrixResult->M33 = 1.0f;
	poMatrixResult->M34 = 0.0f;

	poMatrixResult->M41 = 0.0f;
	poMatrixResult->M42 = 0.0f;
	poMatrixResult->M43 = 0.0f;
	poMatrixResult->M44 = 1.0f;

	return poMatrixResult;
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>* CMatrix4x4<RealNumber>::FillMatrixTranslation(const RealNumber fTx, const RealNumber fTy,  const RealNumber fTz, CMatrix4x4 *poMatrixresult) {
	poMatrixresult->M11 = 1.0f;
	poMatrixresult->M12 = 0.0f;
	poMatrixresult->M13 = 0.0f;
	poMatrixresult->M14 = 0.0f;

	poMatrixresult->M21 = 0.0f;
	poMatrixresult->M22 = 1.0f;
	poMatrixresult->M23 = 0.0f;
	poMatrixresult->M24 = 0.0f;

	poMatrixresult->M31 = 0.0f;
	poMatrixresult->M32 = 0.0f;
	poMatrixresult->M33 = 1.0f;
	poMatrixresult->M34 = 0.0f;

	poMatrixresult->M41 = fTx;
	poMatrixresult->M42 = fTy;
	poMatrixresult->M43 = fTz;
	poMatrixresult->M44 = 1;

	return poMatrixresult;
}

template <class RealNumber>
MATH_INLINE CMatrix4x4<RealNumber>* CMatrix4x4<RealNumber>::FillMatrixScale(const RealNumber fSx, const RealNumber fSy,  const RealNumber fSz, CMatrix4x4 *poMatrixresult) {
	poMatrixresult->M11 = fSx;
	poMatrixresult->M12 = 0.0f;
	poMatrixresult->M13 = 0.0f;
	poMatrixresult->M14 = 0.0f;

	poMatrixresult->M21 = 0.0f;
	poMatrixresult->M22 = fSy;
	poMatrixresult->M23 = 0.0f;
	poMatrixresult->M24 = 0.0f;

	poMatrixresult->M31 = 0.0f;
	poMatrixresult->M32 = 0.0f;
	poMatrixresult->M33 = fSz;
	poMatrixresult->M34 = 0.0f;

	poMatrixresult->M41 = 0;
	poMatrixresult->M42 = 0;
	poMatrixresult->M43 = 0;
	poMatrixresult->M44 = 1;

	return poMatrixresult;
}