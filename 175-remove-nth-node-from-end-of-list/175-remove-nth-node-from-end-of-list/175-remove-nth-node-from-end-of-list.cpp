// 175-remove-nth-node-from-end-of-list.cpp : Defines the entry point for the console application.
// https://www.lintcode.com/problem/remove-nth-node-from-end-of-list/

#include "stdafx.h"

class ListNode
{
public:

	ListNode()
	{
		next = NULL;
	}

	int val;
	ListNode* next;
};

ListNode * removeNthFromEnd(ListNode * head, int n) {
	// write your code here

	ListNode * p1 = head;
	ListNode * p2 = head;

	// p1 moves n steps first
	for (int i = 0; i < n; i++)
		p1 = p1->next;

	// a corner case. a list of length n, remove nth node from end.
	// in this case, remove the fisrt node.
	if (p1 == NULL)
	{
		return head->next;
	}

	while (p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	p2->next = p2->next->next;

	return head;
}
}

int main()
{
	ListNode a;
	ListNode b;
	ListNode c;
	ListNode d;
	ListNode e;

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	a.val = 1;
	b.val = 2;
	c.val = 3;
	d.val = 4;
	e.val = 5;

	ListNode* head = removeNthFromEnd(&a,2);


    return 0;
}

