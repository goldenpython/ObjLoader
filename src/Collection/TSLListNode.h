/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef	__TSLLISTNODE__H__
#define	__TSLLISTNODE__H__

template<class T>
class TSLListNode {
	public:
		TSLListNode();
		TSLListNode(const T &roValue, TSLListNode<T> *poNext = NULL);
		~TSLListNode();

		void SetValue(const T& roValue);
		T& GetValue();

		void SetNext(TSLListNode<T>* poNext);
		TSLListNode<T>* GetNext();

	private:
		T m_oValue;
		TSLListNode<T> *m_poNext;
};

#include "TSLListNode_inline.h"

#endif //__TSLLISTNODE__H__