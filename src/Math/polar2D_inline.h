/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class RealNumber>
MATH_INLINE CPolar2D<RealNumber>::CPolar2D() { 
	d = angle = 0; 
}

template <class RealNumber>
MATH_INLINE CPolar2D<RealNumber>::CPolar2D(RealNumber d) { 
	this->d = d; 
	angle = 0; 
}

template <class RealNumber>
MATH_INLINE CPolar2D<RealNumber>::CPolar2D(RealNumber d, RealNumber angle) { 
	this->d = d; 
	this->angle = angle; 
}

template <class RealNumber>
MATH_INLINE CPolar2D<RealNumber> & CPolar2D<RealNumber>::operator = (const CPolar2D<RealNumber> &p) { 
	d = p.d, angle = p.angle; 
	return *this; 
}

template <class RealNumber>
MATH_INLINE CPolar2D<RealNumber>::CPolar2D(CPoint2D<RealNumber> &point) {
	d = point.DistanceFromOrigin();
	angle = atan2(point.y, point.x);
}  