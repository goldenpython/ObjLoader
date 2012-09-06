/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __MATH_ENGINE__H__
#define __MATH_ENGINE__H__

#include "point2D.h"
#include "polar2D.h"

#include "vector2D.h"
#include "matrix2x2.h"

#include "vector3D.h"
#include "matrix3x3.h"

#include "vector4D.h"
#include "matrix4x4.h"

typedef CMatrix4x4<float> MATRIX4x4f;
typedef CMatrix3x3<float> MATRIX3x3f;
typedef CMatrix2x2<float> MATRIX2x2f;

typedef CVector4D<float> VECTOR4Df;
typedef CVector3D<float> VECTOR3Df;
typedef CVector2D<float> VECTOR2Df;

#endif