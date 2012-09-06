/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "String.h"

CString::CString() {
	m_iStringLength = 0;
	m_szString = NULL;
}

CString::CString(const char *szSource/*, bool bReallocString*/) {
	m_iStringLength = szSource ? (int)strlen(szSource) : 0;
	//m_szString = (char *)(bReallocString ? dupstring(szSource) : szSource);
	m_szString = dupstring(szSource);
}

CString::CString(const CString &source) {
	m_iStringLength = source.m_iStringLength;
	m_szString = dupstring(source.m_szString);
}

CString::~CString() {
	if (m_szString)
		delete m_szString;
}

CString &CString::operator = (const CString &source) {
	m_iStringLength = source.m_iStringLength;

	if (m_szString)
		delete m_szString;

	m_szString = dupstring(source.m_szString);

	return *this;
}

CString &CString::operator = (const char *szString) {
	*this = CString(szString);
	return *this;
}

bool CString::operator == (const CString &source) {
	return Equals(source);
}

CString CString::operator + (char *szString) {
	int len = (int)strlen(szString);
	char *szBuf = new char[m_iStringLength + len + 1];

	if (m_iStringLength)
		memcpy(szBuf, m_szString, m_iStringLength);

	memcpy(szBuf + m_iStringLength, szString, len + 1);

	//return CString(szBuf);
	CString s(szBuf);

	delete []szBuf;

	return s;
}

CString CString::operator + (int value) {
	char aux[20];
	itoa(value, aux, 10);

	return *this + aux;
}

CString CString::operator + (double value) {
	char aux[30];
	sprintf(aux, "%f", value);

	return *this + aux;
}

CString CString::operator + (CString &String) {
	return *this + String.m_szString;
}

char CString::operator [] (int index) {
	return m_szString[index];
}

void CString::ToUpper() {
	if (m_szString)
		strupr(m_szString);
}

void CString::ToLower() {
	if (m_szString)
		strlwr(m_szString);
}

void CString::Tokenize(char ***tokens, int *iNumTokens, char *szDelimiters) {
	char *szBuf = dupstring(m_szString);
	char *p;
	int NumTokens = 0;

	for (p = strtok(szBuf, szDelimiters); p; p = strtok(NULL, szDelimiters), NumTokens++);

	char **tokenArray = NumTokens ? new char *[NumTokens] : NULL;
	strcpy(szBuf, m_szString);
	for (p = strtok(szBuf, szDelimiters), NumTokens = 0; p; p = strtok(NULL, szDelimiters)) 
		tokenArray[NumTokens++] = dupstring(p);

	*tokens = tokenArray;
	*iNumTokens = NumTokens;

	delete szBuf;
}

void CString::Tokenize(char ***tokens, int *iNumTokens, CString &Delimiters) {
	Tokenize(tokens, iNumTokens, Delimiters.m_szString);
}

void CString::Tokenize(CString **tokens, int *iNumTokens, char *szDelimiters) {
	char **tok;

	Tokenize(&tok, iNumTokens, szDelimiters);


	*tokens = *iNumTokens ? new CString[*iNumTokens] : NULL;
	for (int i = 0; i < *iNumTokens; i++)
		(*tokens)[i] = tok[i];

	DELETE_TOKENS_ARRAY(tok, *iNumTokens);
}

void CString::Tokenize(CString **tokens, int *iNumTokens, CString &Delimiters) {
	Tokenize(tokens, iNumTokens, Delimiters.m_szString);
}

bool CString::StartsWith(char *szString) {
	if (!szString || (int)strlen(szString) > m_iStringLength)
		return false;

	return strstr(m_szString, szString) == m_szString;
}

bool CString::StartsWith(CString &string) {
	return StartsWith(string.m_szString);
}

bool CString::EndsWith(char *szString) {
	int len = (int)strlen(szString);
	if (!szString || len > m_iStringLength)
		return false;

	return !strcmp(m_szString + m_iStringLength - len, szString);
}

bool CString::EndsWith(CString &string) {
	return EndsWith(string.m_szString);
}

float CString::ToFloat() {
	float f;
	sscanf(m_szString, "%f", &f);

	return f;
}

int CString::ToInt() {
	int i;
	//sscanf(m_szString, "%d", &i);

	i = atoi(m_szString);

	return i;
}

char *CString::dupstring(const char *szString) {
	if (szString) {
		char *sz = new char[strlen(szString) + 1];
		strcpy(sz, szString);

		return sz;
	} else
		return NULL;
}

int CString::CompareTo(CString &o) {
	return strcmp(m_szString, o.m_szString);
}

int CString::CompareTo(const char *szString) {
	return strcmp(m_szString, szString);
}

bool CString::Equals(const char *szString) {
	return !CompareTo(szString);
}

CString::operator const char* () const {
	return m_szString;
} 