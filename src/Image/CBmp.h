/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __CBMP_H__
#define __CBMP_H__

#include <windows.h>
#include <string.h>
#include "../Stream/stream.h"

class CBmp {
	public:
		bool Load(char *szFileName);
		bool Load(CStreamReader *sr);

		void Draw(HDC dc);

	private:
		BITMAPFILEHEADER	m_bmpFileHader;
		BITMAPINFOHEADER	m_bmpInfoHeader;
		BITMAPINFO			m_bmpInfo;
		byte				*m_bBits;
};

#endif //__CBMP_H__