// 156-merge-two-sorted-lists.cpp : Defines the entry point for the console application.
// https://www.lintcode.com/problem/merge-two-sorted-lists/description

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
	std::string name;
	int val;
	ListNode* next;
};

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
	// write your code here

	ListNode* p1 = l1;
	ListNode* p2 = l2;

	ListNode dummy;
	ListNode* tail = &dummy;

	while (p1 != NULL && p2 != NULL)
	{

		if (p1->val < p2->val)
		{
			ListNode * node = new ListNode(p1->val);

			tail->next = node;

			p1 = p1->next;
		}
		else
		{
			ListNode * node = new ListNode(p2->val);

			tail->next = node;

			p2 = p2->next;
		}

		tail = tail->next;
	}

	if (p1 == NULL)
	{
		tail->next = p2;
	}
	else if (p2 == NULL)
	{
		tail->next = p1;
	}

	return dummy.next;
}
int main()
{
    return 0;
}

