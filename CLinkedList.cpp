#include <iostream>
#include "CLinkedList.h"
using namespace std;

CLinkedList::CLinkedList()
{
	Head = NULL;
	Count = 0;
	Type = 0;
}

PSINGLY_LIST CLinkedList::LastNode()
{
	PSINGLY_LIST node = Head;
	while (node && node->next)
	{
		node = node->next;
	}

	return node;
};

PSINGLY_LIST CLinkedList::FindPrevious(int val)
{
	bool found = false;
	PSINGLY_LIST node = Head, prevNode = NULL;
	while (node)
	{
		if (node->val == val)
		{
			if (node == Head)
				prevNode = Head;

			found = true;
			break;
		}

		prevNode = node;
		node = node->next;
	}

	return found ? prevNode : NULL;
};

bool CLinkedList::Add(int Val)
{
	PSINGLY_LIST lastNode;
	PSINGLY_LIST newNode = new SINGLY_LIST;
	if (!newNode)
		return false;

	newNode->val = Val;
	newNode->next = NULL;

	lastNode = LastNode();
	if (lastNode)
		lastNode->next = newNode;
	else
		Head = newNode;

	Count++;

	return true;
}

bool CLinkedList::Remove(int val)
{
	PSINGLY_LIST prevNode = FindPrevious(val);
	if (prevNode != NULL)
	{
		PSINGLY_LIST remNode;

		if (prevNode != Head)
		{
			remNode = prevNode->next;
			prevNode->next = prevNode->next->next;
		}
		else
		{
			remNode = prevNode;
			Head = remNode->next;
		}

		delete remNode;

		Count--;

		return true;
	}

	return false;
}

void CLinkedList::Reverse()
{
	PSINGLY_LIST prev, current=NULL, node;

	prev = NULL;
	node = Head;
	while (node)
	{
		current = node;
		node = node->next;
		current->next = prev;
		prev = current;
	}

	Head = current;
}

void CLinkedList::Print()
{
	int i;
	PSINGLY_LIST node;

	for (node = Head, i=0; node; node = node->next, i++)
	{
		cout << "node" << i << " = " << node->val;
		cout << endl;
	}
}

CLinkedList::~CLinkedList()
{
	PSINGLY_LIST node;

	node = Head;
	while (node)
	{
		int val = node->val;
		cout << endl << "Removing node = " << val;
		node = node->next;
		Remove(val);
	}
}