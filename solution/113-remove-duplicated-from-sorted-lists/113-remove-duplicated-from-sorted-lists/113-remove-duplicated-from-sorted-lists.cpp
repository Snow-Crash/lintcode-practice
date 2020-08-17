// 113-remove-duplicated-from-sorted-lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
};

ListNode * deleteDuplicates(ListNode * head) {
	// write your code here

	ListNode dummy(-1);
	ListNode * prev = &dummy;
	ListNode * current = head;
	bool duplicate = false;

	if (head == NULL)
		return NULL;

	dummy.next = head;

	while (current != NULL)
	{
		if (current->next != NULL)
		{
			if (current->val == current->next->val)
			{
				duplicate = true;
				prev->next = current->next;
				current = current->next;
			}
			else if (current->val != current->next->val && duplicate == true)
			{
				duplicate = false;
				prev->next = current->next;
				current = current->next;
			}
			else
			{
				prev = current;
				current = current->next;
				duplicate = false;
			}
		}
		else
		{
			if (duplicate == true)
			{
				prev->next = current->next;
				current = current->next;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}

	}

	return dummy.next;
}

int main()
{
	ListNode a(0);
	ListNode b(1);
	ListNode c(1);
	ListNode d(2);
	ListNode e(3);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	
	deleteDuplicates(&a);

    return 0;
}

