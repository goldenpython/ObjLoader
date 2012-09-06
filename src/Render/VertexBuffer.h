/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __VERTEX_BUFFER_H__
#define __VERTEX_BUFFER_H__

class CDisplayDevice;

#include "Render.h"

class CVertexBuffer {
	public:
		CVertexBuffer(float *buffer, int iVertexType, int iNumVertex);
		CVertexBuffer(int iVertexType, int iNumVertex);

		~CVertexBuffer();

		bool DrawPrimitive(CDisplayDevice *device, enum PRIMITIVETYPE type, int iStartVertex, int iNumPrimitives);

		int GetNumVertex();
		int GetVertexType();

		int GetVertexStructSize();

		void* GetVertexBuffer();
		void* GetVertexAtIndex(int iIndex);

		bool IsCached();
		bool Cache(CDisplayDevice *poDisplayDevice);
		void FreeCacheData();

		void *GetCacheData();

	private:
		int m_iNumVertex;
		int m_iVertexType;

		int m_iVertexStructSize;

		bool m_bHasAllocatedMemory;

		void *m_pCachedData;

		float *m_afBuffer;

		void ComputeVertexStructSize();
};

#include "VertexBuffer_inline.h"

#endif //__VERTEX_BUFFER_H__