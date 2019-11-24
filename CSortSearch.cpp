#include <iostream>
#include <time.h>
#include <iomanip>
#include "csortsearch.h"
using namespace std;

CSortSearch::CSortSearch()
{
	InitList();
}

void CSortSearch::InitList()
{
	for (int i = 0; i < kCount; i++)
	{
		Items[i] = rand() % 100;
	}
}

void CSortSearch::Print()
{
	for (int i = 0; i < kCount; i++)
	{
		cout << setfill('0') << setw(2) << Items[i] << " ";
		if (!((i+1) % 20))
			cout << endl;
	}
}

void CSortSearch::Swap(int Idx1, int Idx2)
{
	int temp;

	temp = Items[Idx1];
	Items[Idx1] = Items[Idx2];
	Items[Idx2] = temp;
}

void CSortSearch::BubbleSort()
{
	int i, swapped;

	for (i = 0; ; i++)
	{
		if (Items[i] > Items[i + 1])
		{
			Swap(i, i+1);
			swapped = 1;
		}

		// reached end of list, start from begining again
		if (i >= kCount - 2)
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

void CSortSearch::SelectionSort()
{
	int i, j;

	for (i = 0; i < kCount; i++)
	{
		int least = i;
		for (j = i; j < kCount; j++)
		{
			if (Items[least] > Items[j])
			{
				least = j;
			}
		}

		Swap(i, least);
	}
}

int CSortSearch::BinarySearch(int Val)
{
	int low = 0, mid, high = kCount - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (Items[mid] < Val)
		{
			low = mid + 1;
		}
		else if (Items[mid] > Val)
		{
			high = mid - 1;
		}
		else
			break;
	}

	if (Items[mid] == Val)
		printf("%u is at position:%u", Val, mid);
	else
		printf("%u not found in array", Val);

	return mid;
}
