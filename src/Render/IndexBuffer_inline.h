/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

inline int CIndexBuffer::GetNumIndices() {
	return m_iNumIndices;
}

inline unsigned short* CIndexBuffer::GetIndexBuffer() {
	return m_awIndexBuffer;
}

inline unsigned short* CIndexBuffer::GetIndexAtIndex(int iIndex) {
	return m_awIndexBuffer + iIndex;
}

inline unsigned short& CIndexBuffer::operator [] (int iIndex) {
	return m_awIndexBuffer[iIndex];
}

inline bool CIndexBuffer::IsCached() {
	return m_pCachedData != NULL;
}

inline void *CIndexBuffer::GetCacheData() {
	return m_pCachedData;
}