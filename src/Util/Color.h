/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __COLOR_H__
#define __COLOR_H__

#define COLORARGB_GET_B(a)	((a) & 0xFF)
#define COLORARGB_GET_G(a)	(((a) >> 8) & 0xFF)
#define COLORARGB_GET_R(a)	(((a) >> 16) & 0xFF)
#define COLORARGB_GET_A(a)	(((a) >> 24) & 0xFF)

class CColor {
	public:
		CColor();
		CColor(float red, float green, float blue, float aplha);
		CColor(float red, float green, float blue);
		CColor(int iRed, int iGreen, int iBlue, int iAlpha = 0xFF);
		CColor(int iColorARGB);

		CColor operator * (float f) const;

	float red, green, blue, alpha;
};

#endif //__COLOR_H__