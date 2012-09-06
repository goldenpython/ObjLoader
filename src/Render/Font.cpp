/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "Font.h"

CFont::CFont(CDisplayDevice *poDevice, char *szName, int iWidth, int iHeight, bool bBold, bool bItalic) {
	D3DXFONT_DESC lf;
	ZeroMemory(&lf, sizeof(D3DXFONT_DESC));
	lf.Height = iHeight;
	lf.Width = iWidth;
	lf.Weight = bBold ? 800 : 400;
	lf.Italic = bItalic;
	lf.CharSet = DEFAULT_CHARSET;
	strcpy(lf.FaceName, szName); 

	D3DXCreateFontIndirect(poDevice->m_pDevice, &lf, &m_poFont);
}

void CFont::DrawText(CString &s, int x, int y, int iColor) {
	m_poFont->DrawText(NULL, s, -1, NULL, DT_TOP | DT_LEFT, iColor);
}