/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>::CVector2D() {
	x = y = 0; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>::CVector2D(RealNumber x, RealNumber y) { 
	this->x = x , this->y = y; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>::CVector2D(CVector2D &v) { 
	x = v.x, y = v.y; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>& CVector2D<RealNumber>::operator = (const CVector2D &v) { 
	x = v.x, y = v.y; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber> CVector2D<RealNumber>::operator + (const CVector2D &v) const { 
	return CVector2D(x + v.x, y + v.y); 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>& CVector2D<RealNumber>::operator += (const CVector2D &v) { 
	x += v.x, y += v.y; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>& CVector2D<RealNumber>::operator + () { 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber> CVector2D<RealNumber>::operator - (const CVector2D &v) const { 
	return CVector2D(x - v.x, y - v.y); 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>& CVector2D<RealNumber>::operator -= (const CVector2D &v) {
	x -= v.x, y -= v.y; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber> CVector2D<RealNumber>::operator - () const { 
	return CVector2D(-x, -y); 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber> CVector2D<RealNumber>::operator * (const RealNumber v) const {  
	return CVector2D(x * v, y * v); 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>& CVector2D<RealNumber>::operator *= (RealNumber v) { 
	x *= v, y *= v; return *this; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber> CVector2D<RealNumber>::operator / (RealNumber v) { 
	return CVector2D(x / v, y / v); 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>& CVector2D<RealNumber>::operator /= (RealNumber v) { 
	x /= v, y /= v; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE bool CVector2D<RealNumber>::operator == (const CVector2D &v) const { 
	return x == v.x && y == v.y; 
}

template <class RealNumber>
MATH_INLINE bool CVector2D<RealNumber>::operator != (const CVector2D &v) const { 
	return x != v.x || y != v.y; 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector2D<RealNumber>::Magnitude() const { 
	return MAGNITUDE_VECTOR_2D(x, y); 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector2D<RealNumber>::Magnitude_Pow2() const { 
	return MAGNITUDE_VECTOR_2D_POW2(x, y); 
}

template <class RealNumber>
MATH_INLINE void CVector2D<RealNumber>::Normalize() { 
	RealNumber n = MAGNITUDE_VECTOR_2D(x, y); 
	x /= n; y /= n; 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector2D<RealNumber>::DotProduct(const CVector2D *v) { 
	return x * v->x + y * v->y; 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector2D<RealNumber>::DotProduct(const CVector2D *v1, const CVector2D *v2) { 
	return v1->x * v2->x + v1->y * v2->y; 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber> CVector2D<RealNumber>::operator * (const CMatrix2x2<RealNumber> &m) const { 
	return CVector2D(x * m.M11 + y * m.M21, x * m.M12 + y * m.M22); 
}

template <class RealNumber>
MATH_INLINE CVector2D<RealNumber>& CVector2D<RealNumber>::operator *= (const CMatrix2x2<RealNumber> &m) {
	RealNumber xx = x * m.M11 + y * m.M21, yy = x * m.M12 + y * m.M22; 
	x = xx; y = yy;

	return *this;
}