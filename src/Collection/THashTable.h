/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef	__THASHTABLE__H__
#define	__THASHTABLE__H__

#include "TArray.h"
#include "TSLListNode.h"


template <class TVALUE>
class THashTable {
	public:
		THashTable(int iNumKeys, int (*fctGetHashIndex)(TVALUE v), bool (*fctEqualsWith)(TVALUE v1, TVALUE v2) = NULL);
		~THashTable();

		void Insert(TVALUE v);
		TVALUE* Find(TVALUE v);

	private:
		TArray<TSLListNode<TVALUE>* > *m_aoArray;
		int	(*m_fctHashTableFunction)(TVALUE v);
		bool (*m_fctEqualsWith)(TVALUE v1, TVALUE v2);
};

#include "THashTable_inline.h"

#endif //__THASHTABLE__H__