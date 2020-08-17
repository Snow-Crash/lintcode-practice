// 106-convert-sorted-list-to-binary-search-tree.cpp : Defines the entry point for the console application.
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


class TreeNode {
	public:
		int val;
		TreeNode *left, *right;
		TreeNode(int val) 
		{
			this->val = val;
			this->left = this->right = NULL;
		}
};



TreeNode * divide(ListNode* head)
{

	if (head == NULL)
		return NULL;
	else if (head->next == NULL)
	{
		TreeNode* newTreeNode = new TreeNode(head->val);
		return newTreeNode;
	}

	ListNode * prev = NULL;
	ListNode * fast = head;
	ListNode * slow = head;

	while (fast->next != NULL && fast->next->next != NULL)
	{	
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}


	ListNode* root = slow;

	//break list at node slow
	if (prev != NULL)
		prev->next = NULL;

	TreeNode* node1;
	TreeNode* node2;
	
	if (slow != head)
		node1 = divide(head);
	else
		node1 = NULL;

	node2 = divide(root->next);

	TreeNode* treeRoot = new TreeNode(root->val);

	treeRoot->left = node1;
	treeRoot->right = node2;

	return treeRoot;
}

TreeNode * sortedListToBST(ListNode * head) {
	// write your code here

	TreeNode* treeRoot = divide(head);

	return treeRoot;
}

int main()
{
	ListNode a(-1);
	ListNode b(1);
	//ListNode c(2);

	a.next = &b;
	b.next = NULL;
	//c.next = NULL;

	TreeNode* root = sortedListToBST(&a);

    return 0;
}

