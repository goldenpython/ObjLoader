/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __FILE_STREAM_READER_H__
#define __FILE_STREAM_READER_H__

#include "streamreader.h"
#include "..\\string\\string.h"

class CFileStreamReader : public CStreamReader {
	public:
		CFileStreamReader(char *szFileName);
		~CFileStreamReader();

		int ReadChar();
		int ReadInt();
		int ReadBytes(void *buffer, int iLength);

		void Close();
		void Seek(int offset);
		int GetPosition();
		bool EndOfStream();
		void Reset();
		int GetNumberOfBytesRead();

	private:
		char *m_szFileName;
		FILE *m_file;
};

#endif //__FILE_STREAM_READER_H__