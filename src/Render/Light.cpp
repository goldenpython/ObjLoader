/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "Light.h"

CLight* CLight::CreateDirectionalLight(VECTOR3Df *poDirection, CColor *poColor, CLight *polight) {
	memset(polight, 0, sizeof(CLight));

	polight->m_LightType = LIGHTTYPE_DIRECTIONAL;
	polight->m_oAmbient = *poColor;// * 0.6f;
	polight->m_oDiffuse   = *poColor;
	polight->m_oSpecular  = *poColor;// * 0.6f;
	polight->m_oDirection = *poDirection;

	return polight;
}

CLight* CLight::CreatePointLight(VECTOR3Df *poPosition, CColor *poColor, float fRange, CLight *poLight) {
	memset(poLight, 0, sizeof(CLight));

	poLight->m_LightType = LIGHTTYPE_POINT;
	poLight->m_oAmbient = *poColor;// * 0.6f;
	poLight->m_oDiffuse = *poColor;
	poLight->m_oSpecular = *poColor;// * 0.6f;
	poLight->m_oPosition = *poPosition;

	poLight->m_fConstant = 1.0f;
	poLight->m_fLinear = 0.0f;
	poLight->m_fQuadratic = 0.0f;

	poLight->m_fRange = fRange;

	return poLight;
}

CLight* CLight::CreateSpotLight(VECTOR3Df *poPosition, VECTOR3Df *poDirection, CColor *poColor, float fAngle1, float fAngle2, float fRange, CLight *poLight) {
	memset(poLight, 0, sizeof(CLight));

	poLight->m_LightType = LIGHTTYPE_SPOT;
	poLight->m_oAmbient = *poColor;// * 0.6f;
	poLight->m_oDiffuse = *poColor;
	poLight->m_oSpecular = *poColor;// * 0.6f;
	poLight->m_oPosition = *poPosition;
	poLight->m_oDirection = *poDirection;

	poLight->m_fConstant = 1.0f;
	poLight->m_fLinear = 0.0f;
	poLight->m_fQuadratic = 0.0f;

	poLight->m_fAngle1 = fAngle1;
	poLight->m_fAngle2 = fAngle2;

	poLight->m_fRange = fRange;

	return poLight;
}

enum LIGHTTYPE CLight::GetType() {
	return m_LightType;
}