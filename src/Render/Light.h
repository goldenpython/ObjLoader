/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <string.h>
#include "Render.h"
#include "..\\math\\me.h"
#include "..\\util\\util.h"

class CLight {
	friend class CDisplayDevice;

	public:
		static CLight* CreateDirectionalLight(VECTOR3Df *poDirection, CColor *poColor, CLight *poLight);
		static CLight* CreatePointLight(VECTOR3Df *poPosition, CColor *poColor, float fRange, CLight *poLight);
		static CLight* CreateSpotLight(VECTOR3Df *poPosition, VECTOR3Df *poDirection, CColor *poCcolor, float fAngle, float fAngle2, float fRange, CLight *poLight);


		enum LIGHTTYPE GetType();

	private:
		enum LIGHTTYPE m_LightType;

		VECTOR3Df m_oPosition;
		VECTOR3Df m_oDirection;

		CColor m_oAmbient;
		CColor m_oDiffuse;
		CColor m_oSpecular;

		float m_fRange;

		float m_fConstant;
		float m_fLinear;
		float m_fQuadratic;

		float m_fAngle1;
		float m_fAngle2;
};

#endif //__LIGHT_H__