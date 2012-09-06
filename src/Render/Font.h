/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __FONT_H__
#define __FONT_H__

#include <d3dx9.h>

#include "..\\String\\String.h"
#include "DisplayDevice.h"

class CFont {
	public:
		CFont(CDisplayDevice *poDevice, char *szName, int iWidth, int iHeight, bool bBold = false, bool bItalic = false);

		void DrawText(CString &s, int x, int y, int iColor);

	private:
		ID3DXFont *m_poFont;
};

#endif //__FONT_H__