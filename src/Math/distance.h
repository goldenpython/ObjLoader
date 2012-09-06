/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __DISTANCE__H__
#define __DISTANCE__H__

#define DISTANCE_POW2(x1, y1, x2, y2) ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define DISTANCE(x1, y1, x2, y2) (sqrt(DISTANCE_POW2(x1, y1, x2, y2)))

#define PI 3.141592653589793238462643

#endif