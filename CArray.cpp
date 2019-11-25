#include <iostream>
#include <time.h>
#include <iomanip>
#include "CArray.h"
using namespace std;

CArray::CArray(int arraySize)
{
	Count = arraySize;
	Items = new int[Count];
}

CArray::~CArray()
{
	delete[] Items;
}

void CArray::InitList()
{
	for (int i = 0; i < Count; i++)
	{
		Items[i] = rand() % 100;
	}
}

CArray& CArray::operator+(CArray& srcList)
{
	int srcCount = srcList.GetCount();
	int total = srcCount + Count;
	int *newItems, i, j;
	CArray dest;

	newItems = new int[total];
	if (!newItems)
		goto out;

	j = srcCount - 1;
	i = Count - 1;
	for (int k = total - 1; k >= 0; k--)
	{
		if ( (j < 0) || 
			 ((i >= 0) && (Items[i] > srcList.Get(j))) )
			newItems[k] = Items[i--];
		else
			newItems[k] = srcList.Get(j--);
	}

	delete[] Items;

	Count = total;
	Items = newItems;
out:
	return *this;
}

void CArray::Print()
{
	for (int i = 0; i < Count; i++)
	{
		cout << setfill('0') << setw(2) << Items[i] << " ";
		if (!((i+1) % 20))
			cout << endl;
	}

	cout << endl;
}

void CArray::Swap(int idx1, int idx2)
{
	int temp;

	temp = Items[idx1];
	Items[idx1] = Items[idx2];
	Items[idx2] = temp;
}

void CArray::BubbleSort()
{
	int i, swapped=0;

	for (i = 0; ; i++)
	{
		if (Items[i] > Items[i + 1])
		{
			Swap(i, i+1);
			swapped = 1;
		}

		// reached end of list, start from begining again
		if (i >= Count - 2)
		{
			if (swapped)
			{
				i = -1;
				swapped = 0;
			}
			else
				break;
		}
	}
}

void CArray::SelectionSort()
{
	int i, j;

	for (i = 0; i < Count; i++)
	{
		int least = i;
		for (j = i; j < Count; j++)
		{
			if (Items[least] > Items[j])
			{
				least = j;
			}
		}

		Swap(i, least);
	}
}

int CArray::BinarySearch(int val)
{
	int low = 0, mid, high = Count - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (Items[mid] < val)
		{
			low = mid + 1;
		}
		else if (Items[mid] > val)
		{
			high = mid - 1;
		}
		else
			break;
	}

	if (Items[mid] == val)
		printf("%u is at position:%u", val, mid);
	else
		printf("%u not found in array", val);

	return mid;
}
