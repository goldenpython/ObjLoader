/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __STREAM_READER_H__
#define __STREAM_READER_H__

class CStreamReader {
	public:
		CStreamReader();
		virtual ~CStreamReader();

		virtual int ReadChar() = 0;
		virtual int ReadInt() = 0;
		virtual int ReadBytes(void *buffer, int length) = 0;
		virtual void Close() = 0;
		virtual void Seek(int offset) = 0;
		virtual int GetPosition() = 0;
		virtual bool EndOfStream() = 0;
		virtual void Reset() = 0;
		virtual int GetNumberOfBytesRead() = 0;

	protected:
		int m_iStreamPos;
		int m_iLastNumberOfBytesRead;
};

#endif //__STREAM_READER_H__