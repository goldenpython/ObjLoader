/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "Color.h"

CColor::CColor(float red, float green, float blue, float alpha) {
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

CColor::CColor(float red, float green, float blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = 1.0f;
}

CColor::CColor() {
	red = green = blue = 0.0f;
	alpha = 1.0f;
}

CColor::CColor(int iRed, int iGreen, int iBlue, int iAlpha) {
	red = (float)(iRed / 255.0);
	green = (float)(iGreen / 255.0);
	blue = (float)(iBlue / 255.0);
	alpha = (float)(iAlpha / 255.0);
}

CColor::CColor(int iColorARGB) {
	red = (float)(COLORARGB_GET_R(iColorARGB) / 255.0);
	green = (float)(COLORARGB_GET_G(iColorARGB) / 255.0);
	blue = (float)(COLORARGB_GET_B(iColorARGB) / 255.0);
	alpha = (float)(COLORARGB_GET_A(iColorARGB) / 255.0);
}

CColor CColor::operator * (float f) const {
	return CColor(red *f, green * f, blue * f, alpha);
}