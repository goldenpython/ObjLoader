/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "Material.h"

CMaterial::CMaterial() {
	m_oDiffuse = m_oAmbient = m_oSpecular = m_oEmissive = CColor(0.0f, 0.0f, 0.0f);
	m_fPower = 0.0f;
}

CMaterial::CMaterial(CColor *poDiffuse, CColor *poAmbient, CColor *poSpecular, CColor *poEmissive, float fPower) {
	m_oDiffuse = *poDiffuse;
	m_oAmbient = *poAmbient;
	m_oSpecular = *poSpecular;
	m_oEmissive = *poEmissive;

	m_fPower = fPower;
}

CColor* CMaterial::GetDiffuseColor() {
	return &m_oDiffuse;
}

CColor* CMaterial::GetAmbientColor() {
	return &m_oAmbient;
}

CColor* CMaterial::GetEmissiveColor() {
	return &m_oEmissive;
}

CColor* CMaterial::GetSpecularColor() {
	return &m_oSpecular;
}

float CMaterial::GetPower() {
	return m_fPower;
}

void CMaterial::SetPower(float fPower) {
	m_fPower = fPower;
}
