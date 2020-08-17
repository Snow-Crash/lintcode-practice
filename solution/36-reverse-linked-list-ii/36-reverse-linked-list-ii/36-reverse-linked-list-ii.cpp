// 36-reverse-linked-list-ii.cpp : Defines the entry point for the console application.
// https://www.lintcode.com/problem/reverse-linked-list-ii/description
// https://leetcode.com/problems/reverse-linked-list-ii

#include "stdafx.h"

class ListNode {
public:
	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};
 
class Solution1 {
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

class Solution2 {
public:
	/**
	 * @param head: ListNode head is the head of the linked list
	 * @param m: An integer
	 * @param n: An integer
	 * @return: The head of the reversed ListNode
	 */
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// write your code here

		ListNode dummy(-1);

		dummy.next = head;

		ListNode* start = &dummy;
		ListNode* prev = NULL;
		int i = 0;
		for (; i < m; i++)
		{
			prev = start;
			start = start->next;
		}

		ListNode* prev2 = start;
		ListNode* current = start;
		ListNode* next = start->next;

		while (i < n)
		{
			current = next;
			next = next->next;
			current->next = prev2;
			prev2 = current;
			i++;
		}

		start->next = next;

		if (prev != NULL)
			prev->next = current;

		return dummy.next;
	}
};
class Solution3 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {

		ListNode dummy(-1);

		dummy.next = head;

		ListNode* start = &dummy;
		ListNode* next = NULL;
		ListNode* prev = NULL;
		int i = 0;
		for (; i < m; i++)
		{
			prev = start;
			start = start->next;
		}

		ListNode* prev2 = NULL;
		ListNode* current = start;

		while (i <= n)
		{
			next = current->next;
			current->next = prev2;
			prev2 = current;
			current = next;
			i++;
		}

		start->next = current;

		prev->next = prev2;

		return dummy.next;
	}
};

int main()
{
	// test case 1, m = 2, n = 4
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	//test case 2, m = n = 1
	ListNode a1(5);

	//test case 3, m = 1, n = 4

	Solution3 solution;

	ListNode* head = solution.reverseBetween(&a, 1, 4);

    return 0;
}

