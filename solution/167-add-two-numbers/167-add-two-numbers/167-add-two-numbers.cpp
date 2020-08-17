// 167-add-two-numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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
	int val;
	ListNode* next;
};

ListNode * addLists(ListNode * l1, ListNode * l2) {
	// write your code here

	ListNode dummy;
	ListNode * tail = &dummy;

	ListNode * p1 = l1;
	ListNode * p2 = l2;

	int carry = 0;
	int add1 = 0;
	int add2 = 0;

	while (p1 != NULL || p2 != NULL || carry != 0)
	{
		if (p1 != NULL)
			add1 = p1->val;
		else
			add1 = 0;

		if (p2 != NULL)
			add2 = p2->val;
		else
			add2 = 0;

		int sum = add1 + add2 + carry;

		if (sum > 9)
		{
			carry = 1;
			sum -= 10;
		}
		else
		{
			carry = 0;
		}

		ListNode * node = new ListNode(sum);

		tail->next = node;

		tail = tail->next;

		if (p1 != NULL)
			p1 = p1->next;

		if (p2 != NULL)
			p2 = p2->next;
	}

	return dummy.next;
}

int main()
{

    return 0;
}

