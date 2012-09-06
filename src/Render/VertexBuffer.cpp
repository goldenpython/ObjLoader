/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "VertexBuffer.h"

CVertexBuffer::CVertexBuffer(float *buffer, int iVertexType, int iNumVertex) {
	m_afBuffer = buffer;

	m_iNumVertex = iNumVertex;
	m_iVertexType = iVertexType;

	m_bHasAllocatedMemory = false;

	ComputeVertexStructSize();

	m_pCachedData = NULL;
}

CVertexBuffer::CVertexBuffer(int iVertexType, int iNumVertex) {
	m_iNumVertex = iNumVertex;
	m_iVertexType = iVertexType;

	ComputeVertexStructSize();

	int iVertexStructSize = GetVertexStructSize();

	m_afBuffer = new float[iNumVertex * iVertexStructSize / sizeof(float)];

	m_pCachedData = NULL;
}

CVertexBuffer::~CVertexBuffer() {
	FreeCacheData();

	if (m_bHasAllocatedMemory)
		delete []m_afBuffer;
}

void CVertexBuffer::ComputeVertexStructSize() {
	int iSize = 0;

	if (m_iVertexType & VERTEXFORMAT_XYZ)
		iSize += 3;

	if (m_iVertexType & VERTEXFORMAT_NORMAL)
		iSize += 3;

	if (m_iVertexType & VERTEXFORMAT_TEXTURE)
		iSize += 2;

	if (m_iVertexType & VERTEXFORMAT_COLOR)
		iSize += 1;

	m_iVertexStructSize = iSize * sizeof(float);
}

bool CVertexBuffer::DrawPrimitive(CDisplayDevice *device, enum PRIMITIVETYPE type, int iStartVertex, int iNumPrimitives) {
	return device->DrawPrimitive(type, this, iStartVertex, iNumPrimitives);
}

bool CVertexBuffer::Cache(CDisplayDevice *poDisplayDevice) {
#if RENDER == DX9
	IDirect3DVertexBuffer9* VB;

	int len = GetVertexStructSize() * m_iNumVertex; 
	HRESULT result = poDisplayDevice->m_pDevice->CreateVertexBuffer(
		len, 
		D3DUSAGE_WRITEONLY, 
		poDisplayDevice->GetFVF(GetVertexType()),
		D3DPOOL_SYSTEMMEM, 
		&VB, 
		0);

	if (result != D3D_OK)
		return false;

	char *buffer;
	VB->Lock(0, 0, (void **)&buffer, 0);
	memcpy(buffer, GetVertexBuffer(), len);
	VB->Unlock();

	m_pCachedData = VB;
#endif

	return true;
}

void CVertexBuffer::FreeCacheData() {
#if RENDER == DX9
	if (m_pCachedData) {
		((IDirect3DVertexBuffer9 *)m_pCachedData)->Release();
		m_pCachedData = NULL;
	}
#endif
}