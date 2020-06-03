// 173-insertion-sort-list.cpp : Defines the entry point for the console application.
// https://www.lintcode.com/problem/insertion-sort-list/description

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

class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @return: The head of linked list.
	*/
	ListNode * insertionSortList(ListNode * head)
	{
		// write your code here

		ListNode * sortedListHead = NULL;
		ListNode* current = head;

		while (current != NULL)
		{
			sortedListHead = InsertNode(sortedListHead, current->val);

			current = current->next;
		}

		return sortedListHead;
	}

	ListNode* InsertNode(ListNode* head, int val)
	{
		if (head == NULL || head->val > val)
		{
			ListNode* newNode = new ListNode(val);
			newNode->next = head;
			return newNode;
		}
		else
		{
			ListNode * p = head;
			while (p->next != NULL && p->next->val < val)
			{
				p = p->next;
			}

			ListNode * newNode = new ListNode(val);

			newNode->next = p->next;
			p->next = newNode;

			return head;
		}
	}


int main()
{
    return 0;
}

