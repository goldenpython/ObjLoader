/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>::CVector3D() { 
	x = y = z = 0.0f; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>::CVector3D(RealNumber x, RealNumber y, RealNumber z) { 
	this->x = x , this->y = y, this->z = z; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>::CVector3D(CVector3D &v) { 
	x = v.x, y = v.y; z = v.z; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>::CVector3D(CVector2D<RealNumber> &v) { 
	x = v.x, y = v.y; z = 0.0f; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>& CVector3D<RealNumber>::operator = (const CVector3D &v) { 
	x = v.x, y = v.y, z = v.z; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber> CVector3D<RealNumber>::operator + (const CVector3D &v) const { 
	return CVector3D(x + v.x, y + v.y, z + v.z); 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber> CVector3D<RealNumber>::operator += (const CVector3D &v) { 
	x += v.x, y += v.y, z += v.z;
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>& CVector3D<RealNumber>::operator + () { 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber> CVector3D<RealNumber>::operator - (const CVector3D &v) const { 
	return CVector3D(x - v.x, y - v.y, z - v.z); 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber> CVector3D<RealNumber>::operator -= (const CVector3D &v) { 
	x -= v.x, y -= v.y, z -= v.z; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber> CVector3D<RealNumber>::operator - () const { 
	return CVector3D(-x, -y, -z); 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber> CVector3D<RealNumber>::operator * (const RealNumber v) const {  
	return CVector3D(x * v, y * v, z * v); 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>& CVector3D<RealNumber>::operator *= (const RealNumber v) { 
	x *= v, y *= v, z *= v; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber> CVector3D<RealNumber>::operator / (const RealNumber v) const { 
	return CVector3D(x / v, y / v, z / v); 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>& CVector3D<RealNumber>::operator /= (const RealNumber v) { 
	x /= v, y /= v, z /= v; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE bool CVector3D<RealNumber>::operator == (const CVector3D &v) { 
	return x == v.x && y == v.y && z == v.z; 
}

template <class RealNumber>
MATH_INLINE bool CVector3D<RealNumber>::operator != (const CVector3D &v) { 
	return x != v.x || y != v.y || z != v.z; 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector3D<RealNumber>::Magnitude() const { 
	return MAGNITUDE_VECTOR_3D(x, y, z); 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector3D<RealNumber>::Magnitude_Pow2() const { 
	return MAGNITUDE_VECTOR_3D_POW2(x, y, z); 
}

template <class RealNumber>
MATH_INLINE void CVector3D<RealNumber>::Normalize() { 
	RealNumber n = MAGNITUDE_VECTOR_3D(x, y, z); 
	x /= n; y /= n; z /= n;
}

template <class RealNumber>
MATH_INLINE RealNumber CVector3D<RealNumber>::DotProduct(const CVector3D *v) const { 
	return x * v->x + y * v->y + z * v->z; 
}

template <class RealNumber>
MATH_INLINE RealNumber CVector3D<RealNumber>::DotProduct(const CVector3D *v1, const CVector3D *v2) { 
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z; 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber> CVector3D<RealNumber>::operator * (const CMatrix3x3<RealNumber> &m) const { 
	return CVector3D(
		x * m.M11 + y * m.M21 + z * m.M31,
		x * m.M12 + y * m.M22 + z * m.M32,
		x * m.M13 + y * m.M23 + z * m.M33
	); 
}

template <class RealNumber>
MATH_INLINE CVector3D<RealNumber>& CVector3D<RealNumber>::operator *= (const CMatrix3x3<RealNumber> &m) {
	RealNumber xx = x * m.M11 + y * m.M21 + z * m.M31;
	RealNumber yy = x * m.M12 + y * m.M22 + z * m.M32;
	RealNumber zz = x * m.M13 + y * m.M23 + z * m.M33;

	x = xx, y = yy, z = zz;

	return *this;
} 