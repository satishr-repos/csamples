#pragma once

class CArray
{
	int Count;
	int *Items;

	void Swap(int Idx1, int Idx2);

public:
	CArray(int arraySize=100);
	~CArray();
	void InitList();
	int GetCount() { return Count; }
	CArray& operator + (CArray &srcList);
	int Get(int idx) { return Items[idx]; }
	void Set(int idx, int val) { Items[idx] = val; }
	void Print();
	void BubbleSort();
	void SelectionSort();
	int BinarySearch(int Val);
};