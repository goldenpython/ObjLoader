/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "..\\util\\util.h"

class CMaterial {
	public:
		CMaterial();
		CMaterial(CColor *poDiffuse, CColor *poAmbient, CColor *poSpecular, CColor *poEmissive, float fPower);
		CColor* GetDiffuseColor();
		CColor* GetAmbientColor();
		CColor* GetEmissiveColor();
		CColor* GetSpecularColor();
		float GetPower();
		void SetPower(float fPower);

	private:
		CColor m_oDiffuse;
		CColor m_oAmbient;
		CColor m_oSpecular;
		CColor m_oEmissive;
		float m_fPower;
};

#endif //__MATERIAL_H__