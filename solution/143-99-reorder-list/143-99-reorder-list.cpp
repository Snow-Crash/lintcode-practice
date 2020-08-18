// 143-99-reorder-list.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/reorder-list/

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

void reorderList(ListNode* head) {
	// write your code here

	ListNode* fast = head;
	ListNode* slow = head;

	if (head == NULL || head->next == NULL)
		return;

	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	ListNode* head2 = slow->next;
	slow->next = NULL;

	// reverse second half

	ListNode* prev = NULL;
	ListNode* current = head2;
	ListNode* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	//prev will be the head of second ListNode
	ListNode* p1 = head;
	ListNode* p2 = prev;

	ListNode dummy;

	current = &dummy;

	int count = 0;
	while (p1 != NULL && p2 != NULL)
	{
		if (count % 2 == 0)
		{
			current->next = p1;
			p1 = p1->next;
		}
		else
		{
			current->next = p2;
			p2 = p2->next;
		}

		current = current->next;
		count++;
	}

	if (p1 == NULL)
		current->next = p2;

	if (p2 == NULL)
		current->next = p1;

	head = dummy.next;
}
int main()
{

	ListNode a;
	ListNode b;

	a.val = 1;
	b.val = 2;

	a.next = &b;
	b.next = NULL;

	reorderList(&a);

	return 0;
}

