/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "pack.h"

CPack::CPack() {
	m_iNoSections = 0;
	m_offsets = NULL;
	m_sections = NULL;
	m_szPackName = NULL;
}

CPack::~CPack() {
	Close();
}

bool CPack::Open(char *szPackName, bool bCacheAllSections) {
	Close();

	m_szPackName = CString::dupstring(szPackName);

	CFileStreamReader sr(m_szPackName);

	//read version
	int version = sr.ReadInt();
	if (version != 0)
		return false;

	//read number of sections
	m_iNoSections = sr.ReadInt();

	//alocate memory for section offsets
	SAFE_DELETE_ARRAY(m_offsets);
	m_offsets = new int[m_iNoSections + 1];

	//read section offsets
	if (sr.ReadBytes(m_offsets, sizeof(int) * (m_iNoSections + 1)) != sizeof(int) * (m_iNoSections + 1))
		return false;

	m_sections = new char *[m_iNoSections] ;
	memset(m_sections, 0, sizeof(char *) * m_iNoSections);

	if (bCacheAllSections) 
		CacheAllSections();

	sr.Close();

	return true;
}

char * CPack::CacheSection(int iSectionIndex) {
	if (iSectionIndex < 0 || iSectionIndex >= m_iNoSections)
		return NULL;

	if (m_sections[iSectionIndex] != NULL)
		return m_sections[iSectionIndex];

	int iSize = GetSectionSize(iSectionIndex);
	m_sections[iSectionIndex] = new char[iSize];

	CFileStreamReader sr(m_szPackName);
	sr.Seek(m_offsets[iSectionIndex]);
	sr.ReadBytes(m_sections[iSectionIndex], iSize);

	sr.Close();

	return m_sections[iSectionIndex];
}

char * CPack::CacheSection(CFileStreamReader *sr, int iSectionIndex) {
	if (iSectionIndex < 0 || iSectionIndex >= m_iNoSections)
		return NULL;

	if (m_sections[iSectionIndex] != NULL)
		return m_sections[iSectionIndex];

	int iSize = GetSectionSize(iSectionIndex);
	m_sections[iSectionIndex] = new char[iSize];

	int pos = sr->GetPosition();
	sr->Seek(m_offsets[iSectionIndex] - pos);
	sr->ReadBytes(m_sections[iSectionIndex], iSize);

	return m_sections[iSectionIndex];
}

int CPack::GetSectionSize(int iSectionIndex) {
	if (iSectionIndex < 0 || iSectionIndex >= m_iNoSections)
		return 0;

	return m_offsets[iSectionIndex + 1] - m_offsets[iSectionIndex];
}

char * CPack::GetSection(int iSectionIndex) {
	if (iSectionIndex < 0 || iSectionIndex >= m_iNoSections)
		return NULL;

	return m_sections[iSectionIndex];
}

void CPack::CacheAllSections() {
	CFileStreamReader sr(m_szPackName);

	for (int i = 0; i < m_iNoSections; CacheSection(&sr, i++));
}

void CPack::FreeSection(int iSectionIndex) {
	SAFE_DELETE_ARRAY(m_sections[iSectionIndex]);
}

void CPack::FreeAllSections() {
	SAFE_DELETE_MMARRAY(m_sections, m_iNoSections);
}

void CPack::Close() {
	FreeAllSections();
	SAFE_DELETE_ARRAY(m_offsets);
	SAFE_DELETE_ARRAY(m_szPackName);
}


