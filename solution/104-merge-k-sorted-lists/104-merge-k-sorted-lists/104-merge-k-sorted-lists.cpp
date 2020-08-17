// 104-merge-k-sorted-lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>

using namespace std;


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

ListNode* merge(ListNode* left, ListNode* right)
{

	if (left == NULL)
		return right;

	if (right == NULL)
		return left;

	ListNode dummy;

	ListNode* p1 = left;
	ListNode* p2 = right;
	ListNode* current = &dummy;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->val < p2->val)
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
	}

	if (p1 == NULL)
		current->next = p2;

	if (p2 == NULL)
		current->next = p1;


	return dummy.next;
}

ListNode * divide(vector<ListNode*> &lists, int start, int end)
{

	if (start >= end)
		return lists[end];

	int mid = (start + end) / 2;

	ListNode* left = divide(lists, start, mid);
	ListNode* right = divide(lists, mid + 1, end);

	ListNode* result = merge(left, right);

	return result;

}



ListNode *mergeKLists(vector<ListNode *> &lists) {
	// write your code here

	ListNode* result = divide(lists, 0, lists.size() - 1);

	return result;
}

int main()
{
	

	ListNode a, b, c;
	a.val = 2;
	b.val = 4;
	c.val = -1;

	a.next = &b;
	b.next = NULL;

	c.next = NULL;
	vector<ListNode*> lists{ &a, NULL, &c };

	ListNode * result = mergeKLists(lists);

    return 0;
}

