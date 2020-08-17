// 112-remove-duplicates-from-sorted-list.cpp : Defines the entry point for the console application.
// https://www.lintcode.com/problem/remove-duplicates-from-sorted-list/description

#include "stdafx.h"
#include <iostream>

class ListNode 
{
public:
	int val;
	ListNode *next;

	std::string name;

	ListNode(int val) 
	{
		this->val = val;
		this->next = NULL;
	}
};

ListNode * deleteDuplicates(ListNode * head) {
	// write your code here

	ListNode * current = head;

	if (current == NULL)
		return current;

	ListNode * next = current->next;

	while (next != NULL && current != NULL)
	{
		if (current->val == next->val)
		{
			current->next = next->next;
			next = next->next;
		}
		else
		{
			current = current->next;
			next = next->next;
		}
		//current = current->next;
		
	}

	return head;
}

int main()
{
	ListNode a(10);
	ListNode b(11);
	ListNode c(11);
	ListNode d(12);
	ListNode e(26);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	a.name = "a";
	b.name = "b";
	c.name = "c";
	d.name = "d";
	e.name = "e";

	deleteDuplicates(&a);

    return 0;
}

