/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "filestreamreader.h"

CFileStreamReader::CFileStreamReader(char *szFileName) {
	szFileName = CString::dupstring(szFileName);

	m_file = fopen(szFileName, "rb");
}

CFileStreamReader::~CFileStreamReader() {
	Close();
}

bool CFileStreamReader::EndOfStream() {
	return false;
}

int CFileStreamReader::GetPosition() {
	return ftell(m_file);
}

void CFileStreamReader::Seek(int offset) {
	if (m_file)
		fseek(m_file, offset, SEEK_CUR);
}

void CFileStreamReader::Close() {
	if (m_file)
		fclose(m_file);
}

int CFileStreamReader::ReadChar() {
	char c;

	if ((m_iLastNumberOfBytesRead = (int)fread(&c, sizeof(char), 1, m_file)) != 1)
		return -1;
	else
		return c & 0xFF;
}

int CFileStreamReader::ReadInt() {
	if (!m_file) {
		m_iLastNumberOfBytesRead = 0;
		return 0;
	}

	int a;
	m_iLastNumberOfBytesRead = (int)fread(&a, sizeof(int), 1, m_file);

	return a;
}

int CFileStreamReader::ReadBytes(void *buffer, int iLength) {
	if (!m_file) {
		m_iLastNumberOfBytesRead = 0;
		return 0;
	}


	return m_iLastNumberOfBytesRead = (int)fread(buffer, sizeof(char), iLength, m_file);
}

void CFileStreamReader::Reset() {
	fseek(m_file, 0, SEEK_SET);
}

int CFileStreamReader::GetNumberOfBytesRead() {
	return m_iLastNumberOfBytesRead;
}