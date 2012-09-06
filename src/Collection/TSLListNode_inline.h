/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class T>
TSLListNode<T>::TSLListNode() {
	m_poNext = NULL;
}

template <class T>
TSLListNode<T>::TSLListNode(const T &roValue, TSLListNode<T> *poNext)
		: m_oValue(roValue) {
	m_poNext = poNext;
}

template <class T>
TSLListNode<T>::~TSLListNode() {
/* 	TSLListNode<T> *poCursor = this;
	do {
		TSLListNode<T> *poElement = poCursor;
		poCursor = poCursor->m_poNext;
		delete poElement;
	} while (poCursor); */
}

template <class T>
void TSLListNode<T>::SetValue(const T& roValue) {
	m_oValue = roItem;
}

template <class T>
T& TSLListNode<T>::GetValue() {
	return m_oValue;
}
template <class T>
void TSLListNode<T>::SetNext(TSLListNode<T>* poNext) {
	m_poNext = poNext;
}

template <class T>
TSLListNode<T>* TSLListNode<T>::GetNext() {
	return m_poNext;
}