// 36-reverse-linked-list-ii.cpp : Defines the entry point for the console application.
//

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


class Solution {
public:
	/**
	* @param head: ListNode head is the head of the linked list
	* @param m: An integer
	* @param n: An integer
	* @return: The head of the reversed ListNode
	*/


	ListNode * left;

	bool stop;

	ListNode * reverseBetween(ListNode * head, int m, int n)
	{
		// write your code here
		this->stop = false;

		this->left = head;

		reverse(head, m, n);

		return head;

	}
	void reverse(ListNode* right, int m, int n)
	{
		if (n == 1)
			return;

		right = right->next;

		if (m > 1)
			this->left = this->left->next;


		this->reverse(right, m - 1, n - 1);


		if (this->left == right || right->next == this->left)
		{
			stop = true;
		}

		if (stop != true)
		{
			int t = this->left->val;
			this->left->val = right->val;
			right->val = t;
			this->left = this->left->next;
		}

	}

};

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

    return 0;
}

