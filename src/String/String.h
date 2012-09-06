/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __CSTRING__H__
#define __CSTRING__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class CString {
	public:
		CString();
		CString(const char *szSource/*, bool bReallocString = true*/);
		CString(const CString &source);
		~CString();

		CString &operator = (const CString &source);
		CString &operator = (const char *szString);
		bool operator == (const CString &source);

		CString operator + (char *szString);
		CString operator + (CString &String);
		CString operator + (int value);
		CString operator + (double value);

		int CompareTo(CString &oString);
		int CompareTo(const char *szString);
		bool Equals(const char *szString);

		operator const char* () const;

		char operator [] (int index);

		void ToUpper();
		void ToLower();

		void Tokenize(char ***tokens, int *iNumTokens, char *szDelimiters);
		void Tokenize(char ***tokens, int *iNumTokens, CString &Delimiters);
		void Tokenize(CString **tokens, int *iNumTokens, char *szDelimiters);
		void Tokenize(CString **tokens, int *iNumTokens, CString &Delimiters);

		bool StartsWith(char *szString);
		bool StartsWith(CString &string);
		bool EndsWith(char *szString);
		bool EndsWith(CString &string);

		float ToFloat();
		int ToInt();

		int GetLength() { return m_iStringLength; }
		char *GetBuffer() { return m_szString; }

		static char	*dupstring(const char *szString);

	private:
		int		m_iStringLength;
		char	*m_szString;
};

#define DELETE_TOKENS_ARRAY(tokens, iNumTokens) { \
		if (tokens) { \
			for (int i = 0; i < iNumTokens; i++) \
				if (tokens[i]) \
					delete tokens[i], tokens[i] = NULL; \
			delete tokens; \
			tokens = NULL; \
		} \
	}

#endif //__CSTRING__H__