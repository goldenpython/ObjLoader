/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __INDEX_BUFFER_H__
#define __INDEX_BUFFER_H__

#include "Render.h"

class CIndexBuffer {
	public:
		CIndexBuffer(unsigned short *buffer, int iLength);
		CIndexBuffer(int iLength);
		~CIndexBuffer();

		int GetNumIndices();
		unsigned short *GetIndexBuffer();
		unsigned short *GetIndexAtIndex(int iIndex);
		unsigned short& operator [] (int iIndex);

		bool IsCached();
		bool Cache(CDisplayDevice *poDisplayDevice);
		void FreeCacheData();

		void *GetCacheData();

	private:
		int m_iNumIndices;		
		unsigned short *m_awIndexBuffer;

		void *m_pCachedData;

		bool m_bHasAllocatedMemory;
};

#include "IndexBuffer_inline.h"

#endif