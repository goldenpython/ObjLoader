/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <d3dx9.h>

#include "Render.h"

class CTexture {
	friend class CDisplayDevice;

	public:
		CTexture(CDisplayDevice *pDevice, char *szFileName);
		CTexture(CDisplayDevice *pDevice, void *pBuffer, int iSize);
		~CTexture();

	private:
#if (RENDER == DX9)
		IDirect3DTexture9 *m_poTexture;
#endif
};

#endif