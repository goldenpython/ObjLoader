/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __BYTE_STREAM_READER_H__
#define __BYTE_STREAM_READER_H__

#include <string.h>
#include "streamreader.h"

class CByteStreamReader : public CStreamReader {
	public:
		CByteStreamReader(char *buffer, int iLength);

		int ReadChar();
		int ReadInt();
		int ReadBytes(void *buffer, int iLength);

		void Close();
		void Seek(int offset);
		int GetPosition();
		bool EndOfStream();
		void Reset();
		int GetNumberOfBytesRead() = 0;

	private:
		char *m_buffer;
		int m_iBufferLen;
};

#endif //__BYTE_STREAM_READER_H__