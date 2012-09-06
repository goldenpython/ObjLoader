/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __PACK__H__
#define __PACK__H__

#include <stdio.h>
#include "..\\mem\\memory.h"
#include "..\\String\\String.h"
#include "..\\stream\\stream.h"

class CPack {
	public:
		//constructor
		CPack();

		//destructor
		~CPack();

		bool Open(char *szPackName, bool bCacheAllSections = false);
		char *CacheSection(int iSectionIndex);
		char *GetSection(int iSectionIndex);
		void FreeSection(int iSectionIndex);
		int GetSectionSize(int iSectionIndex);
		void CacheAllSections();
		void FreeAllSections();
		void Close();

	private:
		void CacheAllSections(CFileStreamReader *sr);
		char *CacheSection(CFileStreamReader *sr, int iSectionIndex);

		char *m_szPackName;
		int m_iNoSections;
		int *m_offsets;
		char **m_sections;
};

#endif