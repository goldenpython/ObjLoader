/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>::CMatrix2x2() { 
	M11 = M12 = M21 = M22 = 0.0f; 
}

template <class RealNumber>
CMatrix2x2<RealNumber>::CMatrix2x2(CVector2D<RealNumber> &l1, CVector2D<RealNumber> &l2) { 
	M11 = l1.x; M12 = l1.y; M21 = l2.x; M22 = l2.y; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>::CMatrix2x2(RealNumber m11, RealNumber m12, RealNumber m21, RealNumber m22) { 
	M11 = m11, M12 = m12, M21 = m21, M22 = m22; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>::CMatrix2x2(CMatrix2x2 &m) { 
	M11 = m.M11, M12 = m.M12, M21 = m.M21, M22 = m.M22; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>& CMatrix2x2<RealNumber>::operator = (const CMatrix2x2 &m) { 
	M11 = m.M11, M12 = m.M12, M21 = m.M21, M22 = m.M22; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>& CMatrix2x2<RealNumber>::operator + () { 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber> CMatrix2x2<RealNumber>::operator + (const CMatrix2x2 &m) const { 
	return CMatrix2x2(M11 + m.M11, M12 + m.M12, M21 + m.M21, M22 + m.M22); 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>& CMatrix2x2<RealNumber>::operator += (const CMatrix2x2 &m) { 
	M11 += m.M11, M12 += m.M12, M21 += m.M21, M22 += m.M22; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber> CMatrix2x2<RealNumber>::operator - () const { 
	return CMatrix2x2(-M11, -M12, -M21, -M22); 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber> CMatrix2x2<RealNumber>::operator - (const CMatrix2x2 &m) const { 
	return CMatrix2x2(M11 - m.M11, M12 - m.M12, M21 - m.M21, M22 - m.M22); 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>& CMatrix2x2<RealNumber>::operator -= (const CMatrix2x2 &m) { 
	M11 -= m.M11, M12 -= m.M12, M21 -= m.M21, M22 -= m.M22; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber> CMatrix2x2<RealNumber>::operator * (RealNumber v) const { 
	return CMatrix2x2(M11 * v, M12 * v, M21 * v, M22 * v); 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>& CMatrix2x2<RealNumber>::operator *= (RealNumber v) { 
	M11 *= v, M12 *= v, M21 *= v, M22 *= v; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber> CMatrix2x2<RealNumber>::operator * (const CMatrix2x2 &m) const { 
	return CMatrix2x2(
		M11 * m.M11 + M12 * m.M21, M11 * m.M12 + M12 * m.M22, 
		M21 * m.M11 + M22 * m.M21, M21 * m.M12 + M22 * m.M22
	); 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>& CMatrix2x2<RealNumber>::operator *= (const CMatrix2x2 &m) {
	RealNumber a = M11 * m.M11 + M12 * m.M21;
	RealNumber b = M11 * m.M12 + M12 * m.M22;
	RealNumber c = M21 * m.M11 + M22 * m.M21;
	RealNumber d = M21 * m.M12 + M22 * m.M22; 

	M11 = a;
	M12 = b;
	M21 = c;
	M22 = d;

	return *this;
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber> CMatrix2x2<RealNumber>::operator / (const RealNumber v) const { 
	return CMatrix2x2(M11 / v, M12 / v, M21 / v, M22 / v); 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>& CMatrix2x2<RealNumber>::operator /= (RealNumber v) { 
	M11 /= v, M12 /= v, M21 /= v, M22 /= v; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE RealNumber CMatrix2x2<RealNumber>::Determinant() { 
	return M11 * M22 - M21 * M12; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber> CMatrix2x2<RealNumber>::Transpose() { 
	return CMatrix2x2(M11, M21, M12, M22); 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>* CMatrix2x2<RealNumber>::FillTranspose(CMatrix2x2 *m) { 
	m->M11 = M11, m->M12 = M21, m->M21 = M12, m->M22 = M22; 
	return m; 
};

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>* CMatrix2x2<RealNumber>::FillIdentity(CMatrix2x2 *out) { 
	out->M11 = 1.0f, out->M12 = 0.0f, out->M21 = 0.0f, out->M22 = 1.0f; 
	return out; 
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>* CMatrix2x2<RealNumber>::FillZeroMatrix(CMatrix2x2 *out) {
	out->M11 = out->M12 = out->M21 = out->M22 = 0.0f;
	return out;
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber>* CMatrix2x2<RealNumber>::FillMatrixRotation(CMatrix2x2 *out, RealNumber angle) {
	out->M11 = cos(angle);
	out->M12 = sin(angle);
	out->M21 = -out->M12;
	out->M22 = out->M11;

	return out;
}

template <class RealNumber>
MATH_INLINE CMatrix2x2<RealNumber> CMatrix2x2<RealNumber>::MatrixRotation(RealNumber angle) {
	return CMatrix2x2(
		cos(angle), sin(angle),
		-sin(angle), cos(angle)
	);
}