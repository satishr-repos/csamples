#pragma once

typedef struct __SinglyList
{
	int val;
	struct __SinglyList* next;

} SINGLY_LIST, * PSINGLY_LIST;

class CList
{
	PSINGLY_LIST	Head;
	int				Count;
	int				Type;

public:
	CList();
	bool Add(int Val);
	bool Remove(int Val);
	void Reverse();
	void Print();
	~CList();

private:
	PSINGLY_LIST LastNode();
	PSINGLY_LIST FindPrevious(int Val);
};
