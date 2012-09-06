/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "Texture.h"

CTexture::CTexture(CDisplayDevice *pDevice, char *szFileName) {
	bool bResult;

#if (RENDER == DX9)
	bResult = D3DXCreateTextureFromFile(pDevice->m_pDevice, szFileName, &m_poTexture) == D3D_OK;
#endif
}

CTexture::CTexture(CDisplayDevice *pDevice, void *pBuffer, int iSize) {
	bool bResult;

#if (RENDER == DX9)
	bResult = D3DXCreateTextureFromFileInMemory(pDevice->m_pDevice, pBuffer, iSize, &m_poTexture) == D3D_OK;
#endif
}

CTexture::~CTexture() {
#if (RENDER == DX9)
	if (m_poTexture)
		m_poTexture->Release();
#endif
}