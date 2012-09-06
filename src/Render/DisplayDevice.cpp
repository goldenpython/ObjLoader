/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "DisplayDevice.h"

bool CDisplayDevice::CreateDevice(HWND hwnd, bool windowed, int iWidth, int iHeight) {
	HRESULT hr = 0;

	// Step 1: Create the IDirect3D9 object.

	IDirect3D9* d3d9 = 0;
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	if( !d3d9 )
	{
		::MessageBox(0, "Direct3DCreate9() - FAILED", 0, 0);
		return false;
	}

	// Step 2: Check for hardware vp.

	D3DCAPS9 caps;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	int vp = 0;
	if( caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT )
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	// Step 3: Fill out the D3DPRESENT_PARAMETERS structure.

	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth            = iWidth;
	d3dpp.BackBufferHeight           = iHeight;
	d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount            = 1;
	d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality         = 0;
	d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD; 
	d3dpp.hDeviceWindow              = hwnd;
	d3dpp.Windowed                   = windowed;
	d3dpp.EnableAutoDepthStencil     = true; 
	d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;
	d3dpp.Flags                      = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

	// Step 4: Create the device.

	hr = d3d9->CreateDevice(
		D3DADAPTER_DEFAULT, // primary adapter
		D3DDEVTYPE_HAL,         // device type
		hwnd,               // window associated with device
		vp,                 // vertex processing
		&d3dpp,             // present parameters
		&m_pDevice);            // return created device

	if (FAILED(hr)) {
		// try again using a 16-bit depth buffer
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		hr = d3d9->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hwnd,
			vp,
			&d3dpp,
			&m_pDevice);

		if (FAILED(hr)) {
			d3d9->Release(); // done with d3d9 object
			::MessageBox(0, "CreateDevice() - FAILED", 0, 0);
			return false;
		}
	}

	d3d9->Release(); // done with d3d9 object

	return true;
} 

bool CDisplayDevice::ClearViewport(int iColor) {
	return m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, iColor, 1.0f, 0) == D3D_OK;
}

bool CDisplayDevice::Present() {
	return m_pDevice->Present(NULL, NULL, NULL, NULL) == D3D_OK;
}

bool CDisplayDevice::SetFillMode(enum FILLMODE FillMode) {
	DWORD iMode;

	switch (FillMode) {
		case FILLMODE_SOLID:
			iMode = D3DFILL_SOLID;
			break;

		case FILLMODE_WIREFRAME:
			iMode = D3DFILL_WIREFRAME;
			break;

		default:
			return false;
	}

	return m_pDevice->SetRenderState(D3DRS_FILLMODE, iMode) == D3D_OK;
}

bool CDisplayDevice::EnableSpecular(bool bEnable) {
	return m_pDevice->SetRenderState(D3DRS_SPECULARENABLE, bEnable) == D3D_OK;
}

bool CDisplayDevice::SetShadeMode(enum SHADEMODE ShadeMode) {
	DWORD iMode;

	switch (ShadeMode) {
		case SHADEMODE_FLAT:
			iMode = D3DSHADE_FLAT;
			break;

		case SHADEMODE_GOURAUD:
			iMode = D3DSHADE_GOURAUD;
			break;

		default:
			return false;
	}

	return m_pDevice->SetRenderState(D3DRS_SHADEMODE, iMode) == D3D_OK;
}

bool CDisplayDevice::EnableNormalizeNormals(bool bEnable) {
	return m_pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, bEnable) == D3D_OK;
}

bool CDisplayDevice::SetCullMode(enum CULLMODE CullMode) {
	DWORD iMode;

	switch (CullMode) {
		case CULLMODE_NONE:
			iMode = D3DCULL_NONE;
			break;

		case CULLMODE_CW:
			iMode = D3DCULL_CW;
			break;

		case CULLMODE_CCW:
			iMode = D3DCULL_CCW;
			break;

		default:
			return false;
	}
	
	return m_pDevice->SetRenderState(D3DRS_CULLMODE, iMode) == D3D_OK;
}

bool CDisplayDevice::EnableLighting(bool bEnable) {
	return m_pDevice->SetRenderState(D3DRS_LIGHTING, bEnable) == D3D_OK;
}

bool CDisplayDevice::SetProjection(float fFOV, float fRatio, float fZNear, float fZFar) {
	//D3DXMATRIX MatrixProjection1;
	//D3DXMatrixPerspectiveFovLH(&MatrixProjection1, fFOV, fRatio, fZNear, fZFar);

	float yScale = cos(fFOV / 2) / sin(fFOV / 2);
	float xScale = yScale / fRatio;

	MATRIX4x4f MatrixProjection(
		xScale, 0, 0, 0,
		0, yScale, 0, 0,
		0, 0, fZFar / (fZFar - fZNear), 1,
		0, 0, -fZNear * fZFar / (fZFar - fZNear), 0
	); 

	return m_pDevice->SetTransform(D3DTS_PROJECTION, (D3DXMATRIX *) &MatrixProjection) == D3D_OK;
}

bool CDisplayDevice::BeginScene() {
	return m_pDevice->BeginScene() == D3D_OK;
}

bool CDisplayDevice::EndScene() {
	return m_pDevice->EndScene() == D3D_OK;
}

int CDisplayDevice::GetFVF(int iFormat) {
	int iDXFormat = 0;

	if (iFormat & VERTEXFORMAT_XYZ)
		iDXFormat |= D3DFVF_XYZ;
	
	if (iFormat & VERTEXFORMAT_NORMAL)
		iDXFormat |= D3DFVF_NORMAL;
	
	if (iFormat & VERTEXFORMAT_TEXTURE)
		iDXFormat |= D3DFVF_TEX1;

	if (iFormat & VERTEXFORMAT_COLOR)
		iDXFormat |= D3DFVF_DIFFUSE;

	return iDXFormat;
}

D3DPRIMITIVETYPE CDisplayDevice::GetPrimitivetype(enum PRIMITIVETYPE type) {
	switch (type) {
		case PRIMITIVETYPE_TRIANGLE_LIST:
			return D3DPT_TRIANGLELIST;
	}

	return D3DPT_TRIANGLELIST;
};

bool CDisplayDevice::SetCamera(VECTOR3Df *position, VECTOR3Df *target, VECTOR3Df *up) {
	D3DXMATRIX V;
	D3DXVECTOR3 *v = (D3DXVECTOR3 *)position;
	D3DXMatrixLookAtLH(&V, (D3DXVECTOR3 *)position, (D3DXVECTOR3 *)target, (D3DXVECTOR3 *)up);

	return m_pDevice->SetTransform(D3DTS_VIEW, &V) == D3D_OK; 
}

bool CDisplayDevice::DrawPrimitive(enum PRIMITIVETYPE type, CVertexBuffer *oVertexBuffer, int iStartVertex, int iNumPrimitives) {
	IDirect3DVertexBuffer9* VB;

	switch (type) {
		case PRIMITIVETYPE_TRIANGLE_LIST:
		{
			int len;
			HRESULT result;

			m_pDevice->SetFVF(GetFVF(oVertexBuffer->GetVertexType()));
			
			if (oVertexBuffer->IsCached()) {
				m_pDevice->SetStreamSource(0, (IDirect3DVertexBuffer9 *)oVertexBuffer->GetCacheData(), 0, oVertexBuffer->GetVertexStructSize());
				result = m_pDevice->DrawPrimitive(GetPrimitivetype(type), iStartVertex, iNumPrimitives);
			} else {
				len = oVertexBuffer->GetVertexStructSize() * iNumPrimitives * 3; //oVertexBuffer->GetNumVertex() * oVertexBuffer->GetVertexStructSize();
				result = m_pDevice->CreateVertexBuffer(len, D3DUSAGE_WRITEONLY, GetFVF(oVertexBuffer->GetVertexType()),	D3DPOOL_SYSTEMMEM, &VB, 0);

				if (result != D3D_OK)
					return false;

				char *buffer;
				VB->Lock(0, 0, (void **)&buffer, 0);

				memcpy(buffer, (char *)oVertexBuffer->GetVertexBuffer() + (iStartVertex * oVertexBuffer->GetVertexStructSize()), len);

				VB->Unlock();

				m_pDevice->SetStreamSource(0, VB, 0, oVertexBuffer->GetVertexStructSize());
				result = m_pDevice->DrawPrimitive(GetPrimitivetype(type), 0, iNumPrimitives);

				VB->Release();
			}

			if (result != D3D_OK) 
				return false;			

			break;
		}

		default:
			return false;
	}

	return true;
}

bool CDisplayDevice::DrawIndexedPrimitive(enum PRIMITIVETYPE type, CVertexBuffer *oVertexBuffer, CIndexBuffer *oIndexBuffer, int iStartIndex, int iNumPrimitives) {
	IDirect3DVertexBuffer9* VB;
	IDirect3DIndexBuffer9* IB;

	switch (type) {
		case PRIMITIVETYPE_TRIANGLE_LIST:
		{
			int len;
			HRESULT result;
			char *buffer;
			bool bCachedVertexBuffer = false;
			bool bCachedIndexBuffer = false;
			
			if (!oVertexBuffer->IsCached()) {
				if (!oVertexBuffer->Cache(this))
					return false;

				bCachedVertexBuffer = true;
			} 
			
			VB = (IDirect3DVertexBuffer9 *)oVertexBuffer->GetCacheData();

			if (!oIndexBuffer->IsCached()) {
				result = m_pDevice->CreateIndexBuffer(
					len = iNumPrimitives * 3 * sizeof(unsigned short), 
					D3DUSAGE_WRITEONLY,
					D3DFMT_INDEX16, 
					D3DPOOL_SYSTEMMEM,
					&IB, 0);

				if (result != D3D_OK) {
					if (bCachedVertexBuffer)
						VB->Release();

					return false;
				}

				IB->Lock(0, 0, (void **)&buffer, 0);
				memcpy(buffer, oIndexBuffer->GetIndexAtIndex(iStartIndex), len);
				IB->Unlock();

				bCachedIndexBuffer = true;
			} else
				IB = (IDirect3DIndexBuffer9 *)oIndexBuffer->GetCacheData();

			m_pDevice->SetFVF(GetFVF(oVertexBuffer->GetVertexType()));
			m_pDevice->SetStreamSource(0, VB, 0, oVertexBuffer->GetVertexStructSize());
			m_pDevice->SetIndices(IB);

			result = m_pDevice->DrawIndexedPrimitive(GetPrimitivetype(type), 0, 0, oVertexBuffer->GetNumVertex(), bCachedIndexBuffer ? 0 : iStartIndex, iNumPrimitives);
			//ca result = m_pDevice->DrawPrimitive(GetPrimitivetype(type), 0, iNumPrimitives);

			if (bCachedVertexBuffer) {
				//VB->Release();	
				oVertexBuffer->FreeCacheData();
			}

			if (!oIndexBuffer->IsCached())
				IB->Release();

			if (result != D3D_OK) 
				return false;			
			break;
		}
	}

	return true;
}

bool CDisplayDevice::SetWorldTransform(MATRIX4x4f *poMatrixTransform) {
	return m_pDevice->SetTransform(D3DTS_WORLD, (D3DMATRIX *)poMatrixTransform) == D3D_OK;
}

bool CDisplayDevice::SetMaterial(CMaterial *poMaterial) {
	D3DMATERIAL9 material;

	CColor *color = poMaterial->GetAmbientColor();
	material.Ambient = D3DXCOLOR(color->red, color->green, color->blue, color->alpha);

	color = poMaterial->GetDiffuseColor();
	material.Diffuse = D3DXCOLOR(color->red, color->green, color->blue, color->alpha);

	color = poMaterial->GetEmissiveColor();
	material.Emissive = D3DXCOLOR(color->red, color->green, color->blue, color->alpha);

	color = poMaterial->GetSpecularColor();
	material.Specular = D3DXCOLOR(color->red, color->green, color->blue, color->alpha);

	material.Power = poMaterial->GetPower();


	return m_pDevice->SetMaterial(&material) == D3D_OK;
}

bool CDisplayDevice::SetTexture(CTexture *poTexture) {
	return m_pDevice->SetTexture(0, poTexture ? poTexture->m_poTexture : NULL) == D3D_OK;
}

bool CDisplayDevice::SetLight(int iIndex, CLight *poLight) {
	if (!poLight) 
		return m_pDevice->LightEnable(iIndex, false) == D3D_OK;

	D3DLIGHT9 light;
	memset(&light, 0, sizeof(D3DLIGHT9));

	light.Ambient.r = poLight->m_oAmbient.red;
	light.Ambient.g = poLight->m_oAmbient.green;
	light.Ambient.b = poLight->m_oAmbient.blue;
	light.Ambient.a = poLight->m_oAmbient.alpha;

	light.Diffuse.r = poLight->m_oDiffuse.red;
	light.Diffuse.g = poLight->m_oDiffuse.green;
	light.Diffuse.b = poLight->m_oDiffuse.blue;
	light.Diffuse.a = poLight->m_oDiffuse.alpha;

	light.Specular.r = poLight->m_oSpecular.red;
	light.Specular.g = poLight->m_oSpecular.green;
	light.Specular.b = poLight->m_oSpecular.blue;
	light.Specular.a = poLight->m_oSpecular.alpha;

	light.Attenuation0 = poLight->m_fConstant;
	light.Attenuation1 = poLight->m_fLinear;
	light.Attenuation1 = poLight->m_fQuadratic;

	light.Direction = *((D3DXVECTOR3 *) &(poLight->m_oDirection));
	light.Position = *((D3DXVECTOR3 *) &(poLight->m_oPosition));

	light.Theta = poLight->m_fAngle1;
	light.Phi = poLight->m_fAngle2;

	light.Range = poLight->m_fRange;
	light.Falloff = 1.0f;

	D3DLIGHTTYPE type;

	switch (poLight->m_LightType) {
		case LIGHTTYPE_DIRECTIONAL:
			type = D3DLIGHT_DIRECTIONAL;
			break;

		case LIGHTTYPE_POINT:
			type = D3DLIGHT_POINT;
			break;

		case LIGHTTYPE_SPOT:
			type = D3DLIGHT_SPOT;
			break;
	}

	light.Type = type;

	bool result = m_pDevice->SetLight(iIndex, &light) == D3D_OK;

	if (!result)
		return false;

	result = m_pDevice->LightEnable(iIndex, true) == D3D_OK;

	return result;
}