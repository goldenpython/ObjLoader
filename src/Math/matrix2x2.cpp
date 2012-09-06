/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "matrix2x2.h"

template <>
const CMatrix2x2<float> CMatrix2x2<float>::Identity = CMatrix2x2(
	1.0f, 0.0f, 
	0.0f, 1.0f
);

template <>
const CMatrix2x2<float> CMatrix2x2<float>::Zero = CMatrix2x2(
	0.0f, 0.0f, 
	0.0f, 0.0f
); 