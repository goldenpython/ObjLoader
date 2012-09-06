/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef	__TARRAY__H__
#define	__TARRAY__H__

#include "..\util\util.h"

template <class T>
class TArray {
	public:
		TArray(int iNoElements = 0, int iGrowBy = 1);
		~TArray();

		int GetSize() const;
		int GetGrowBy() const;
		void SetGrowBy(int iGrowBy);
		int GetMaxSize() const;

		T* GetArray();
		void Append(const T& roElement);

		void Insert(int index, const T& roElement);

		int Find(const T& roElement);

		void Remove(int index);
		void RemoveAll();

		void FillWithZero();

		T& operator[] (int index);

		void SetMaxSize(int iMaxSize);

	private:
		T*	m_aoArray;
		int m_iMaxSize, m_iCurrentSize, m_iGrowBy;
};

#include "TArray_inline.h"

#endif	//__TARRAY__H__