// 35-reverse-linked-list.cpp : Defines the entry point for the console application.
// https://www.lintcode.com/problem/reverse-linked-list/
// https://leetcode.com/problems/reverse-linked-list/

#include "stdafx.h"
#include <vector>
#include <unordered_map>

using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	//ListNode(int val) {
	//this->val = val;
	//this->next = NULL;
	//}
};

ListNode* reverse(ListNode * head) {
	// write your code here

	ListNode* original_head = head;

	ListNode* current = head;
	ListNode* next = current->next;
	ListNode* prev = current;
	while (next != NULL)
	{
		if (next->next != NULL)
		{
			current = next;
			next = next->next;
			current->next = prev;
			prev = current;
		}
		else
		{
			next->next = current;
			head = next;
			break;
		}
	}

	original_head->next = NULL;

	return head;
}

class Solution {
public:
	ListNode* reverseList(ListNode* head) {

		ListNode* prev = NULL;
		ListNode* current = head;
		ListNode* next = NULL;

		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		return prev;
	}
};

int main()
{
	ListNode a, b, c, d, e;

	a.val = 0;
	b.val = 1;
	c.val = 2;
	d.val = 3;
	e.val = 4;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL;

	// solution 1
	//ListNode* head = reverse(&a);

	// solution 2
	Solution solution;
	ListNode * reversed = solution.reverseList(&a);

    return 0;
}

