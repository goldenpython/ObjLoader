/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "bytestreamreader.h"

CByteStreamReader::CByteStreamReader(char *buffer, int iLength) {
	m_iBufferLen = iLength;
	m_buffer = buffer;
}

int CByteStreamReader::ReadChar() {
	if (m_iStreamPos >= m_iBufferLen) {
		m_iLastNumberOfBytesRead = 0;
		return -1;
	}

	m_iLastNumberOfBytesRead = 1;
	return *(m_buffer + m_iStreamPos++) & 0xFF;
}

int CByteStreamReader::ReadInt() {
	m_iLastNumberOfBytesRead = sizeof(int);
	return *((int *)(m_buffer + m_iStreamPos++));
}

int CByteStreamReader::ReadBytes(void *buffer, int iLength) {
	if (m_iStreamPos + iLength < m_iBufferLen) {
		memcpy(buffer, m_buffer, iLength);
		m_iStreamPos += iLength;
		m_iLastNumberOfBytesRead = iLength;

		return iLength;
	} else {
		int BytesRead = m_iBufferLen - m_iStreamPos;
		memcpy(buffer, m_buffer, BytesRead);
		m_iStreamPos = m_iBufferLen;
		m_iLastNumberOfBytesRead = BytesRead;

		return BytesRead;
	}
}

void CByteStreamReader::Seek(int offset) {
	m_iStreamPos += offset;
}

void CByteStreamReader::Close() {
}

int CByteStreamReader::GetPosition() {
	return m_iStreamPos;
}

bool CByteStreamReader::EndOfStream() {
	return m_iStreamPos >= m_iBufferLen;
}

void CByteStreamReader::Reset() {
	m_iStreamPos = 0;
}

int CByteStreamReader::GetNumberOfBytesRead() {
	return m_iLastNumberOfBytesRead;
}