/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class TVALUE>
THashTable<TVALUE>::THashTable(int iNumKeys, int (*fctGetHashIndex)(TVALUE &v), bool (*fctEqualsWith)(TVALUE &v1, TVALUE &v2)) {
	m_aoArray = new TArray<TSLListNode<TVALUE>* >(iNumKeys);
	m_aoArray->FillWithZero();

	m_fctHashTableFunction = fctGetHashIndex;
	m_fctEqualsWith = fctEqualsWith;

	m_iNumItemsInHashTable = 0;
}

template <class TVALUE>
THashTable<TVALUE>::~THashTable() {
	int dim = m_aoArray->GetSize();

	for (int i = 0; i < dim; i++) {
		for (TSLListNode<TVALUE> *node = (*m_aoArray)[i]; node; ) {
			TSLListNode<TVALUE> *last = node;
			node = node->GetNext();

			delete last;
		}
	}

	delete m_aoArray;
}

template <class TVALUE>
void THashTable<TVALUE>::Insert(TVALUE &v) {
	int key = m_fctHashTableFunction(v) % m_aoArray->GetMaxSize();

	TSLListNode<TVALUE> *node = new TSLListNode<TVALUE> (v, (*m_aoArray)[key]);
	(*m_aoArray)[key] = node;

	m_iNumItemsInHashTable++;
}

template <class TVALUE>
TVALUE* THashTable<TVALUE>::Find(TVALUE &v) {
	int key = m_fctHashTableFunction(v) % m_aoArray->GetMaxSize();

	if (m_fctEqualsWith) {
		for (TSLListNode<TVALUE> *node = (*m_aoArray)[key]; node; node = node->GetNext())
			if (m_fctEqualsWith(node->GetValue(), v))
				return &(node->GetValue());
	} else {
		for (TSLListNode<TVALUE> *node = (*m_aoArray)[key]; node; node = node->GetNext())
			if (node->GetValue() == v)
				return &(node->GetValue());
	}

	return NULL;
}

template <class TVALUE>
void THashTable<TVALUE>::Resize(int iNewValue) {
}
