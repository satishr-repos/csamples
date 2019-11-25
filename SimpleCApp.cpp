// SimpleCApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <time.h>
#include "CLinkedList.h"
#include "CArray.h"
using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void fibonacci(int n)
{
	int a, b, c, i;

	a = 0;
	b = 1;

	for (i = 2; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;

		printf("%u ", c);
	}

}

int main()
{
	CLinkedList list;
	CArray sort;
	int val;

	/* initialize random seed: */
	srand((unsigned int)time(NULL));
	//fibonacci(25);

	/* sort operations
	*/
	sort.InitList();
	cout << "Unsorted List" << endl;
	sort.Print();

	cout << "Bubble Sort" << endl;
	sort.BubbleSort();
	sort.Print();

	cout << "Enter a value for BinarySearch: ";
	cin >> val;
	sort.BinarySearch(val);


	/* list operations
	for (int i = 0; i < 10; i++)
	{
		list.Add(rand() % 100);
	}

	cout << "Original List...." << endl << endl;
	list.Print();
	cout << endl;

	cout << "Reversed List..." << endl << endl;
	list.Reverse();
	list.Print();
	cout << endl;
	*/
}

