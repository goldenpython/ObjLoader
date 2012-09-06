/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

template <class T>
TArray<T>::TArray(int iNoElements, int iGrowBy) {
	if (iNoElements < 0)
		iNoElements = 0;

	if (iGrowBy < 0)
		iGrowBy = 0;

	m_iCurrentSize = iNoElements;
	m_iMaxSize = iNoElements;
	m_iGrowBy = iGrowBy;

	m_aoArray = (m_iMaxSize > 0) ? new T[m_iMaxSize] : NULL;
}

template <class T>
TArray<T>::~TArray() {
	if (m_aoArray)
		delete []m_aoArray;
}

template <class T>
inline int TArray<T>::GetSize() const {
	return m_iCurrentSize;
}

template <class T>
inline int TArray<T>::GetGrowBy() const {
	return m_iGrowBy;
}

template <class T>
inline void TArray<T>::SetGrowBy(int iGrowBy) {
	m_iGrowBy = iGrowBy;
}

template <class T>
inline int TArray<T>::GetMaxSize() const {
	return m_iMaxSize;
} 

template <class T>
inline T* TArray<T>::GetArray() {
	return m_aoArray;
}

template <class T>
void TArray<T>::Append(const T& roElement) {
	if (m_iCurrentSize == m_iMaxSize) 
		SetMaxSize(m_iCurrentSize + m_iGrowBy);

	m_aoArray[m_iCurrentSize++] = roElement;
}

template <class T>
int TArray<T>::Find(const T& roElement) {
	for (int i = 0; i < m_iCurrentSize; i++)
		if (m_aoArray[i] == roElement)
			return i;

	return -1;
}

template <class T>
void TArray<T>::SetMaxSize(int iMaxSize) {
	if (iMaxSize < 0)
		iMaxSize = 0;

	int iNoElementsToCopy = MIN(iMaxSize, m_iCurrentSize);

	T *aoNewArray = iMaxSize > 0 ? new T[iMaxSize] : NULL;

	if (iNoElementsToCopy > 0) 
		for (int i = 0; i < iNoElementsToCopy; i++)
			aoNewArray[i] = m_aoArray[i];

	if (m_aoArray)
		delete []m_aoArray;

	m_aoArray = aoNewArray;

	m_iCurrentSize = iNoElementsToCopy;
	m_iMaxSize = iMaxSize;
}

template <class T>
inline T& TArray<T>::operator[] (int index) {
	return m_aoArray[index];
}

template <class T>
void TArray<T>::Insert(int index, const T& roElement) {
	if (index < 0)
		index = 0;

	if (index > m_iCurrentSize)
		index = m_iCurrentSize;

	if (m_iCurrentSize >= m_iMaxSize)
		SetMaxSize(m_iMaxSize + m_iGrowBy);

	if (index < m_iCurrentSize)
		for (int i = m_iCurrentSize; i > index; i--)
			m_aoArray[i] = m_aoArray[i - 1];

	m_aoArray[index] = roElement;
	m_iCurrentSize++;
}

template <class T>
void TArray<T>::Remove(int index) {
	if (index < 0)
		index = 0;

	if (index >= m_iCurrentSize)
		index = m_iCurrentSize - 1;

	for (int i = index; i < m_iCurrentSize - 1; i++)
		m_aoArray[i] = m_aoArray[i + 1];

	m_aoArray[--m_iCurrentSize] = T();
}

template <class T>
void TArray<T>::RemoveAll() {
	for (int i = 0; i < m_iCurrentSize; i++)
		m_aoArray[i] = T();

	m_iCurrentSize = 0;
}

template <class T>
void TArray<T>::FillWithZero() {
	memset(m_aoArray, 0, m_iMaxSize * sizeof(T));
} 