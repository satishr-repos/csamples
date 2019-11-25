#pragma once

class CArray
{
	static const int kCount = 100;
	int Items[kCount];

	void Swap(int Idx1, int Idx2);

public:
	CArray();
	void InitList();
	void Print();
	void BubbleSort();
	void SelectionSort();
	int BinarySearch(int Val);
};