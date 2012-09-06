/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>::CMatrix3x3() { 
	M11 = M12 = M13 = M21 = M22 = M23 = M31 = M32 = M33 = 0.0f; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>::CMatrix3x3(
			RealNumber m11, RealNumber m12, RealNumber m13, 									
			RealNumber m21, RealNumber m22, RealNumber m23, 
			RealNumber m31, RealNumber m32, RealNumber m33) { 
	M11 = m11, M12 = m12, M13 = m13, 
	M21 = m21, M22 = m22, M23 = m23, 
	M31 = m31, M32 = m32, M33 = m33; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>::CMatrix3x3(CMatrix3x3 &m) { 
	M11 = m.M11, M12 = m.M12, M13 = m.M13, 
	M21 = m.M21, M22 = m.M22, M23 = m.M23, 
	M31 = m.M31, M32 = m.M32, M33 = m.M33; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>& CMatrix3x3<RealNumber>::operator = (const CMatrix3x3 &m) { 
	M11 = m.M11, M12 = m.M12, M13 = m.M13, 
	M21 = m.M21, M22 = m.M22, M23 = m.M23, 
	M31 = m.M31, M32 = m.M32, M33 = m.M33; 

	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>& CMatrix3x3<RealNumber>::operator + () { 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber> CMatrix3x3<RealNumber>::operator + (const CMatrix3x3 &m) const { 
	return CMatrix3x3(
		M11 + m.M11, M12 + m.M12, M13 + m.M13, 
		M21 + m.M21, M22 + m.M22, M23 + m.M23, 
		M31 + m.M31, M32 + m.M32, M33 + m.M33
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>& CMatrix3x3<RealNumber>::operator += (const CMatrix3x3 &m) { 
	M11 += m.M11, M12 += m.M12, M13 += m.M13, 
	M21 += m.M21, M22 += m.M22, M23 += m.M23, 
	M31 += m.M31, M32 += m.M32, M33 += m.M33; 

	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber> CMatrix3x3<RealNumber>::operator - () const { 
	return CMatrix3x3(-M11, -M12, -M13, -M21, -M22, -M23, -M31, -M32, -M33); 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber> CMatrix3x3<RealNumber>::operator - (const CMatrix3x3 &m) const { 
	return CMatrix3x3(
		M11 - m.M11, M12 - m.M12, M13 - m.M13, 
		M21 - m.M21, M22 - m.M22, M23 - m.M23, 
		M31 - m.M31, M32 - m.M32, M33 - m.M33
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>& CMatrix3x3<RealNumber>::operator -= (const CMatrix3x3 &m) { 
	M11 -= m.M11, M12 -= m.M12, M13 -= m.M13, 
	M21 -= m.M21, M22 -= m.M22, M23 -= m.M23, 
	M31 -= m.M31, M32 -= m.M32, M33 -= m.M33; 

	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber> CMatrix3x3<RealNumber>::operator * (const RealNumber v) const { 
	return CMatrix3x3(
		M11 * v, M12 * v, M13 * v, 
		M21 * v, M22 * v, M23 * v, 
		M31 * v, M32 * v, M33 * v
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>& CMatrix3x3<RealNumber>::operator *= (const RealNumber v) { 
	M11 *= v, M12 *= v, M13 *= v, 
	M21 *= v, M22 *= v, M23 *= v, 
	M31 *= v, M32 *= v, M33 *= v; 

	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber> CMatrix3x3<RealNumber>::operator * (const CMatrix3x3 &m) const {
	return CMatrix3x3(M11 * m.M11 + M12 * m.M21 + M13 * m.M31, 
		M11 * m.M12 + M12 * m.M22 + M13 * m.M32,
		M11 * m.M13 + M12 * m.M23 + M13 * m.M33,
		M21 * m.M11 + M22 * m.M21 + M23 * m.M31,
		M21 * m.M12 + M22 * m.M22 + M23 * m.M32,
		M21 * m.M13 + M22 * m.M23 + M23 * m.M33,
		M31 * m.M11 + M32 * m.M21 + M33 * m.M31,
		M31 * m.M12 + M32 * m.M22 + M33 * m.M32,
		M31 * m.M13 + M32 * m.M23 + M33 * m.M33
	);
};

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>& CMatrix3x3<RealNumber>::operator *= (const CMatrix3x3 &m) {
	RealNumber a11 = M11 * m.M11 + M12 * m.M21 + M13 * m.M31;
	RealNumber a12 = M11 * m.M12 + M12 * m.M22 + M13 * m.M32;
	RealNumber a13 = M11 * m.M13 + M12 * m.M23 + M13 * m.M33;
	RealNumber a21 = M21 * m.M11 + M22 * m.M21 + M23 * m.M31;
	RealNumber a22 = M21 * m.M12 + M22 * m.M22 + M23 * m.M32;
	RealNumber a23 = M21 * m.M13 + M22 * m.M23 + M23 * m.M33;
	RealNumber a31 = M31 * m.M11 + M32 * m.M21 + M33 * m.M31;
	RealNumber a32 = M31 * m.M12 + M32 * m.M22 + M33 * m.M32;
	RealNumber a33 = M31 * m.M13 + M32 * m.M23 + M33 * m.M33;

	M11 = a11;
	M12 = a12;
	M13 = a13;
	M21 = a21;
	M22 = a22;
	M23 = a23;
	M31 = a31;
	M32 = a32;
	M33 = a33;

	return *this;
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber> CMatrix3x3<RealNumber>::operator / (const RealNumber v) const { 
	return CMatrix3x3(
		M11 / v, M12 / v, M13 / v, 
		M21 / v, M22 / v, M23 / v, 
		M31 / v, M32 / v, M33 / v
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>& CMatrix3x3<RealNumber>::operator /= (const RealNumber v) { 
	M11 /= v, M12 /= v, M13 /= v, 
	M21 /= v, M22 /= v, M23 /= v, 
	M31 /= v, M32 /= v, M33 /= v; 

	return *this; 
}

template <class RealNumber>
MATH_INLINE RealNumber CMatrix3x3<RealNumber>::Determinant() const { 
	return M11 * M22 * M33 + M21 * M32 * M13 + M31 * M12 * M23
		- M13 * M22 * M31 - M23 * M32 * M11 - M33 * M12 * M21; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber> CMatrix3x3<RealNumber>::Transpose() const { 
	return CMatrix3x3(
		M11, M21, M31, 
		M12, M22, M32, 
		M13, M23, M33
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>* CMatrix3x3<RealNumber>::FillTranspose(CMatrix3x3 *m) { 
	m->M11 = M11, m->M12 = M21, m->M13 = M31, 
	m->M21 = M12, m->M22 = M22, m->M23 = M32, 
	m->M31 = M13, m->M32 = M23, m->M33 = M33; 

	return m; 
};

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>* CMatrix3x3<RealNumber>::FillIdentity(CMatrix3x3 *out) { 
	out->M11 = 1.0f, out->M12 = 0.0f, out->M13 = 0.0f,
	out->M21 = 0.0f, out->M22 = 1.0f, out->M23 = 0.0f,
	out->M31 = 0.0f, out->M32 = 0.0f, out->M33 = 1.0f; 

	return out; 
}

template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>* CMatrix3x3<RealNumber>::FillZero(CMatrix3x3 *out) { 
	out->M11 = 0.0f, out->M12 = 0.0f, out->M13 = 0.0f,
	out->M21 = 0.0f, out->M22 = 0.0f, out->M23 = 0.0f,
	out->M31 = 0.0f, out->M32 = 0.0f, out->M33 = 0.0f; 

	return out; 
}


template <class RealNumber>
MATH_INLINE CMatrix3x3<RealNumber>::CMatrix3x3(CVector3D<RealNumber> &l1, CVector3D<RealNumber> &l2, CVector3D<RealNumber> &l3) { 
	M11 = l1.x; M12 = l1.y; M13 = l1.z;
	M21 = l2.x; M22 = l2.y; M23 = l2.z;
	M31 = l3.x; M32 = l3.y; M33 = l3.z;
}

template <class RealNumber>
CMatrix3x3<RealNumber>* CMatrix3x3<RealNumber>::FillMatrixRotationOX(const RealNumber fAngle, CMatrix3x3 *poMatrixResult) {
	poMatrixResult->M11 = 1.0f;
	poMatrixResult->M12 = 0.0f;
	poMatrixResult->M13 = 0.0f;

	poMatrixResult->M21 = 0.0f;
	poMatrixResult->M22 = cos(fAngle);
	poMatrixResult->M23 = sin(fAngle);

	poMatrixResult->M31 = 0.0f;
	poMatrixResult->M32 = -sin(fAngle);
	poMatrixResult->M33 = cos(fAngle);

	return poMatrixResult;
}

template <class RealNumber>
CMatrix3x3<RealNumber>* CMatrix3x3<RealNumber>::FillMatrixRotationOY(const RealNumber fAngle, CMatrix3x3 *poMatrixResult) {
	poMatrixResult->M11 = cos(fAngle);
	poMatrixResult->M12 = 0.0f;
	poMatrixResult->M13 = -sin(fAngle);

	poMatrixResult->M21 = 0.0f;
	poMatrixResult->M22 = 1.0f;
	poMatrixResult->M23 = 0.0f;

	poMatrixResult->M31 = sin(fAngle);
	poMatrixResult->M32 = 0;
	poMatrixResult->M33 = cos(fAngle);

	return poMatrixResult;
}

template <class RealNumber>
CMatrix3x3<RealNumber>* CMatrix3x3<RealNumber>::FillMatrixRotationOZ(const RealNumber fAngle, CMatrix3x3 *poMatrixResult) {
	poMatrixResult->M11 = cos(fAngle);
	poMatrixResult->M12 = sin(fAngle);
	poMatrixResult->M13 = 0.0f;

	poMatrixResult->M21 = -sin(fAngle);
	poMatrixResult->M22 = cos(fAngle);
	poMatrixResult->M23 = 0.f;

	poMatrixResult->M31 = 0.0f;
	poMatrixResult->M32 = 0.0f;
	poMatrixResult->M33 = 1.0f;

	return poMatrixResult;
}

template <class RealNumber>
static CMatrix3x3<RealNumber>* CMatrix3x3<RealNumber>::FillScaleMatrix(
		const RealNumber fSx, 
		const RealNumber fSy, 
		const RealNumber fSz, 
		CMatrix3x3 *poMatrixResult) {

	poMatrixResult->M11 = fSx;
	poMatrixResult->M12 = 0.0f;
	poMatrixResult->M13 = 0.0f;

	poMatrixResult->M21 = 0.0f;
	poMatrixResult->M22 = fSy;
	poMatrixResult->M23 = 0.0f;

	poMatrixResult->M31 = 0.0f;
	poMatrixResult->M32 = 0.0f;
	poMatrixResult->M33 = fSy;

	return poMatrixResult;
}