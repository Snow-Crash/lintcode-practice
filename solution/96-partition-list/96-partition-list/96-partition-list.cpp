// 96-partition-list.cpp : Defines the entry point for the console application.
// https://www.lintcode.com/problem/partition-list/description

#include "stdafx.h"

#include <string>
#include <iostream>


class ListNode 
{
public:

	ListNode()
	{
		val = val;
		next = NULL;
	};

	ListNode(int val)
	{
		val = val;
		next = NULL;
	};
	std::string name;
	int val;
	ListNode* next;
};


ListNode * partition(ListNode * head, int x)
{	
	ListNode * head1 = new ListNode;
	ListNode * head2 = new ListNode;

	ListNode * tail1 = head1;
	ListNode * tail2 = head2;

	ListNode* current = head;

	while (current != NULL)
	{
		ListNode * node = new ListNode;
		node->val = current->val;

		if (current->val < x)
		{
			tail1->next = node;
			tail1 = node;
		}
		else
		{
			tail2->next = node;
			tail2 = node;
		}

		current = current->next;
	}

	tail1->next = head2->next;

	return head1->next;
}



int main()
{	
	ListNode a, b, c, d, e, f;

	f.name = "f";
	f.val = 2;
	f.next = NULL;

	e.name = "e";
	e.val = 5;
	e.next = &f;

	d.name = "d";
	d.val = 2;
	d.next = &e;

	c.name = "c";
	c.val = 3;
	c.next = &d;

	b.name = "b";
	b.val = 4;
	b.next = &c;

	a.name = "a";
	a.val = 1;
	a.next = &b;



	std::cout << a.name;

	ListNode* h = partition(&a, 3);

    return 0;
}

