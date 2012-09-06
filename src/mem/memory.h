/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __MEMORY__H__
#define __MEMORY__H__

#include <stdio.h>

#define DELETE_OBJECT(a)				{ if (a) { delete a; a = NULL; } };
#define SIMPLE_DELETE_ARRAY(a)			((delete [](a), a = NULL))
#define SAFE_DELETE_ARRAY(a)			{ if (a) (delete [](a), a = NULL); }
#define SAFE_DELETE_MMARRAY(a, size)	{ if (a) { for (int i = 0; i < size; i++) SAFE_DELETE_ARRAY(a[i]); } SAFE_DELETE_ARRAY(a) }

#endif