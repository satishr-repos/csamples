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
	CArray arr1(20), arr2(20);
	int val;

	/* initialize random seed: */
	srand((unsigned int)time(NULL));
	//fibonacci(25);

	/* sort operations
	*/
	arr1.InitList();
	cout << "Unsorted array 1" << endl;
	arr1.Print();

	arr2.InitList();
	cout << "Unsorted array 2" << endl;
	arr2.Print();

	cout << "Bubble Sort Array1" << endl;
	arr1.BubbleSort();
	arr1.Print();

	cout << "Selection Sort Array2" << endl;
	arr2.SelectionSort();
	arr2.Print();

	cout << "Merge Array 1 & 2" << endl;
	arr1 = arr1 + arr2;
	arr1.Print();


	//cout << "Enter a value for BinarySearch: ";
	//cin >> val;
	//arr1.BinarySearch(val);


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

