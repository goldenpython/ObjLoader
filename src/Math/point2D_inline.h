/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class RealNumber>
MATH_INLINE CPoint2D<RealNumber>::CPoint2D() { 
	x = y = 0.0f; 
};

template <class RealNumber>
MATH_INLINE CPoint2D<RealNumber>::CPoint2D(RealNumber x, RealNumber y) { 
	this->x = x; this->y = y; 
};

template <class RealNumber>
MATH_INLINE CPoint2D<RealNumber>::CPoint2D(CPoint2D &point) { 
	x = point.x; y = point.y; 
};

template <class RealNumber>
MATH_INLINE RealNumber CPoint2D<RealNumber>::DistanceFromOrigin() const { 
	return DISTANCE(x, y, 0.0f, 0.0f); 
};

template <class RealNumber>
MATH_INLINE RealNumber CPoint2D<RealNumber>::DistanceFromOriginPow2() const { 
	return DISTANCE_POW2(x, y, 0, 0); 
};

template <class RealNumber>
MATH_INLINE RealNumber CPoint2D<RealNumber>::Distance(const CPoint2D &point) const { 
	return DISTANCE(x, y, point.x, point.y); 
}

template <class RealNumber>
MATH_INLINE RealNumber CPoint2D<RealNumber>::DistancePow2(const CPoint2D &point) const { 
	return DISTANCE_POW2(x, y, point.x, point.y); 
}

template <class RealNumber>
MATH_INLINE CPoint2D<RealNumber>& CPoint2D<RealNumber>::operator = (const CPoint2D &p) { 
	x = p.x, y = p.y; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE bool CPoint2D<RealNumber>::operator == (const CPoint2D &p) const { 
	return x == p.x && y == p.y; 
}

template <class RealNumber>
MATH_INLINE bool CPoint2D<RealNumber>::operator != (const CPoint2D &p) const { 
	return x != p.x || y != p.y; 
}

template <class RealNumber>
MATH_INLINE CPoint2D<RealNumber>::CPoint2D(CPolar2D<RealNumber> &point) {
	x = point.d * sin(point.angle);
	y = point.d * cos(point.angle);
} 