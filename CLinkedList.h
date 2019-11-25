#pragma once

typedef struct __SinglyList
{
	int val;
	struct __SinglyList* next;

} SINGLY_LIST, * PSINGLY_LIST;

class CLinkedList
{
	PSINGLY_LIST	Head;
	int				Count;
	int				Type;

public:
	CLinkedList();
	bool Add(int Val);
	bool Remove(int Val);
	void Reverse();
	void Print();
	~CLinkedList();

private:
	PSINGLY_LIST LastNode();
	PSINGLY_LIST FindPrevious(int Val);
};
