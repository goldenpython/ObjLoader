/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "IndexBuffer.h"

CIndexBuffer::CIndexBuffer(int iLenght) {
	m_awIndexBuffer = new unsigned short[iLenght];
	m_iNumIndices = iLenght;

	m_bHasAllocatedMemory = true;
	m_pCachedData = NULL;
}

CIndexBuffer::CIndexBuffer(unsigned short *buffer, int iLenght) {
	m_awIndexBuffer = buffer;
	m_iNumIndices = iLenght;

	m_bHasAllocatedMemory = false;
	m_pCachedData = NULL;
}

CIndexBuffer::~CIndexBuffer() {
	FreeCacheData();

	if (m_bHasAllocatedMemory)
		delete m_awIndexBuffer;
}

bool CIndexBuffer::Cache(CDisplayDevice *poDisplayDevice) {
#if RENDER == DX9
	IDirect3DIndexBuffer9* IB;

	int len = sizeof(unsigned short) * m_iNumIndices; 
	HRESULT result = poDisplayDevice->m_pDevice->CreateIndexBuffer(
		len, 
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16, 
		D3DPOOL_SYSTEMMEM,
		&IB, 
		0);

	if (result != D3D_OK)
		return false;

	char *buffer;
	IB->Lock(0, 0, (void **)&buffer, 0);
	memcpy(buffer, GetIndexBuffer(), len);
	IB->Unlock();

	m_pCachedData = IB;
#endif

	return true;
}

void CIndexBuffer::FreeCacheData() {
#if RENDER == DX9
	if (m_pCachedData) {
		((IDirect3DIndexBuffer9 *)m_pCachedData)->Release();
		m_pCachedData = NULL;
	}
#endif
}