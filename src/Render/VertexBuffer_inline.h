inline int CVertexBuffer::GetNumVertex() {
	return m_iNumVertex;
}

inline int CVertexBuffer::GetVertexType() {
	return m_iVertexType;
}

inline void* CVertexBuffer::GetVertexBuffer() {
	return m_afBuffer;
}

inline void* CVertexBuffer::GetVertexAtIndex(int iIndex) {
	return ((char *)m_afBuffer + iIndex * m_iVertexStructSize);
}

inline int CVertexBuffer::GetVertexStructSize() {
	return m_iVertexStructSize;
}

inline bool CVertexBuffer::IsCached() {
	return m_pCachedData != NULL;
}

inline void *CVertexBuffer::GetCacheData() {
	return m_pCachedData;
}