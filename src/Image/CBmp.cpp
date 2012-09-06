/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "CBmp.h"

bool CBmp::Load(char *szFileName) {
	CFileStreamReader sr(szFileName);

	return Load(&sr);
}

bool CBmp::Load(CStreamReader *sr) {
	int iBytesRead;

	iBytesRead = sr->ReadBytes(&m_bmpFileHader, sizeof(BITMAPFILEHEADER));
	if (iBytesRead != sizeof(BITMAPFILEHEADER))
		return false;
	if (m_bmpFileHader.bfType != 0x4D42)
		return false;


	iBytesRead = sr->ReadBytes(&m_bmpInfoHeader, sizeof(BITMAPINFOHEADER));
	if (iBytesRead != sizeof(BITMAPINFOHEADER))
		return false;
	if (m_bmpInfoHeader.biBitCount != 24)
		return false; 


	byte *bArray = new byte[m_bmpInfoHeader.biSizeImage];
	if (!bArray)
		return false;
	iBytesRead = sr->ReadBytes(bArray, m_bmpInfoHeader.biSizeImage);
	if (iBytesRead != m_bmpInfoHeader.biSizeImage)
		return false;
	m_bBits = bArray;

	memset(&m_bmpInfo.bmiColors, 0, sizeof(RGBQUAD));
	memcpy(&m_bmpInfo.bmiHeader, &m_bmpInfoHeader, sizeof(BITMAPINFOHEADER));


	return true;
}

void CBmp::Draw(HDC dc) {
	StretchDIBits(
		dc,
		0, 0, m_bmpInfo.bmiHeader.biWidth, m_bmpInfo.bmiHeader.biHeight,
		0, 0, m_bmpInfo.bmiHeader.biWidth, m_bmpInfo.bmiHeader.biHeight,
		m_bBits,
		&m_bmpInfo,
		DIB_RGB_COLORS,
		SRCCOPY);
}