#include "bytestream.h"

CByteStream::CByteStream(char *buffer, int iLength) {
	m_iBufferLen = iLength;
	m_buffer = buffer;
}

char CByteStream::ReadChar() {
	return *(m_buffer + m_iStreamPos++);
}

int CByteStream::ReadInt() {
	return *((int *)(m_buffer + m_iStreamPos++));
}

void CByteStream::ReadBytes(char *buffer, int iLength) {
	memcpy(buffer, m_buffer, iLength);
	m_iStreamPos += iLength;
}

void CByteStream::Seek(int offset) {
	m_iStreamPos += offset;
}