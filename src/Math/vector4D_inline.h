/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>::CVector4D() { 
	x = y = z = w = 0.0f; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>::CVector4D(RealNumber x, RealNumber y, RealNumber z, RealNumber w) { 
	this->x = x , this->y = y, this->z = z, this->w = w; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>::CVector4D(CVector4D &v) { 
	x = v.x, y = v.y; z = v.z, w = v.w; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>::CVector4D(CVector3D<RealNumber> &v) { 
	x = v.x, y = v.y; z = v.z; w = 0.0f; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>::CVector4D(CVector2D<RealNumber> &v) { 
	x = v.x, y = v.y; z = w = 0.0f; 
} 

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>& CVector4D<RealNumber>::operator = (const CVector4D &v) { 
	x = v.x, y = v.y, z = v.z, w = v.w; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber> CVector4D<RealNumber>::operator + (const CVector4D &v) const { 
	return CVector4D(x + v.x, y + v.y, z + v.z, w + v.w); 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber> CVector4D<RealNumber>::operator += (const CVector4D &v) { 
	x += v.x, y += v.y, z += v.z, w += v.w;
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>& CVector4D<RealNumber>::operator + () { 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber> CVector4D<RealNumber>::operator - (const CVector4D &v) const { 
	return CVector4D(x - v.x, y - v.y, z - v.z, w - v.w); 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber> CVector4D<RealNumber>::operator -= (const CVector4D &v) { 
	x -= v.x, y -= v.y, z -= v.z, w -= v.w; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber> CVector4D<RealNumber>::operator - () const { 
	return CVector4D(-x, -y, -z, -w); 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber> CVector4D<RealNumber>::operator * (const RealNumber v) const {  
	return CVector4D(x * v, y * v, z * v, w * v); 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>& CVector4D<RealNumber>::operator *= (const RealNumber v) { 
	x *= v, y *= v, z *= v, w *= v; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber> CVector4D<RealNumber>::operator / (const RealNumber v) const { 
	return CVector4D(x / v, y / v, z / v, w / v); 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>& CVector4D<RealNumber>::operator /= (const RealNumber v) { 
	x /= v, y /= v, z /= v, w /= v; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE bool CVector4D<RealNumber>::operator == (const CVector4D &v) { 
	return x == v.x && y == v.y && z == v.z && w == v.w; 
}

template <class RealNumber>
MATH_INLINE bool CVector4D<RealNumber>::operator != (const CVector4D &v) { 
	return x != v.x || y != v.y || z != v.z || w != v.w; 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector4D<RealNumber>::Magnitude() const { 
	return MAGNITUDE_VECTOR_4D(x, y, z, w); 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector4D<RealNumber>::Magnitude_Pow2() const { 
	return MAGNITUDE_VECTOR_4D_POW2(x, y, z, w); 
}

template <class RealNumber>
MATH_INLINE void CVector4D<RealNumber>::Normalize() { 
	RealNumber n = MAGNITUDE_VECTOR_4D(x, y, z, w); 
	x /= n; y /= n; z /= n, w /= n;
}

template <class RealNumber>
MATH_INLINE RealNumber CVector4D<RealNumber>::DotProduct(const CVector4D *v) const { 
	return x * v->x + y * v->y + z * v->z + w * v->z; 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector4D<RealNumber>::DotProduct(const CVector4D *v1, const CVector4D *v2) { 
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + v1->w * v2->w; 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber> CVector4D<RealNumber>::operator * (const CMatrix4x4<RealNumber> &m) const { 
	return CVector4D(
		x * m.M11 + y * m.M21 + z * m.M31 + w * m.M41,
		x * m.M12 + y * m.M22 + z * m.M32 + w * m.M42,
		x * m.M13 + y * m.M23 + z * m.M33 + w * m.M43,
		x * m.M14 + y * m.M24 + z * m.M34 + w * m.M44
		); 
}

template <class RealNumber>
MATH_INLINE CVector4D<RealNumber>& CVector4D<RealNumber>::operator *= (const CMatrix4x4<RealNumber> &m) {
	RealNumber xx = x * m.M11 + y * m.M21 + z * m.M31 + w * m.M41;
	RealNumber yy = x * m.M12 + y * m.M22 + z * m.M32 + w * m.M42;
	RealNumber zz = x * m.M13 + y * m.M23 + z * m.M33 + w * m.M43;
	RealNumber ww = x * m.M14 + y * m.M24 + z * m.M34 + w * m.M44;

	x = xx, y = yy, z = zz, ww = w;

	return *this;
} 