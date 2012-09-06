/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __DISPLAY_DEVICE__
#define __DISPLAY_DEVICE__

#include <d3dx9.h>

#include <windows.h>

#include "RenderConstants.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Material.h"
#include "Texture.h"
#include "Light.h"

#include "..\\math\\me.h"

//class CDisplayDevice;
class CLight;

class CDisplayDevice {
	public:
		friend class CVertexBuffer;
		friend class CIndexBuffer;
		friend class CTexture;
		friend class CFont;

		CDisplayDevice() {};

		bool CreateDevice(HWND hwnd, bool windowed, int iWidth, int iHeight);

		bool ClearViewport(int iColor);
		bool Present();

		bool SetFillMode(enum FILLMODE FillMode);
		bool EnableSpecular(bool bEnable = true);
		bool SetShadeMode(enum SHADEMODE ShadeMode);
		bool EnableNormalizeNormals(bool bEnable = true);
		bool SetCullMode(enum CULLMODE CullMode);
		bool EnableLighting(bool bEnable = true);
		bool SetProjection(float fFOV, float fRatio, float fZNear, float fZFar);
		bool DrawPrimitive(enum PRIMITIVETYPE type, CVertexBuffer *oVertexBuffer, int iStartVertex, int iNumPrimitives);
		bool DrawIndexedPrimitive(enum PRIMITIVETYPE type, CVertexBuffer *oVertexBuffer, CIndexBuffer *oIndexBuffer, int iStartIndex, int iNumPrimitives);
		bool SetWorldTransform(MATRIX4x4f *poMatrixTransform);
		bool SetMaterial(CMaterial *poMaterial);
		bool SetTexture(CTexture *poTexture);

		bool Cache();

		bool BeginScene();
		bool EndScene();

		bool SetCamera(VECTOR3Df *position, VECTOR3Df *target, VECTOR3Df *up);
		bool SetLight(int iIndex, CLight *poLight);

		int GetFVF(int iFormat);
		D3DPRIMITIVETYPE GetPrimitivetype(enum PRIMITIVETYPE type);

	private:
		IDirect3DDevice9 *m_pDevice;
};

#endif