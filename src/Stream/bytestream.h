#ifndef __BYTE_STREAM_H__
#define __BYTE_STREAM_H__

#include <string.h>
#include "stream.h"

class CByteStream : public CStream {
	public:
		CByteStream(char *buffer, int iLength);

		char ReadChar() = 0;
		int ReadInt() = 0;
		void ReadBytes(char *buffer, int iLength);

		void Close() = 0;
		void Seek(int offset) = 0;

	private:
		char *m_buffer;
		int m_iBufferLen;
};

#endif