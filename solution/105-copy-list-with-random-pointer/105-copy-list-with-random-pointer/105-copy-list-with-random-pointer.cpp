// 105-copy-list-with-random-pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};

RandomListNode *copyRandomList(RandomListNode *head) {
	// write your code here

	if (head == NULL)
		return head;

	RandomListNode * current = head;

	RandomListNode * newNode = NULL;
	while (current != NULL)
	{
		newNode = new RandomListNode(current->label);

		newNode->next = current->next;

		current->next = newNode;

		current = newNode->next;
	}

	//add random pointer

	current = head;
	while (current != NULL)
	{
		if (current->random == NULL)
			current->next->random = NULL;
		else
			current->next->random = current->random->next;

		current = current->next->next;
	}

	//disconnect new list from old list

	RandomListNode * newHead = NULL;

	current = head;
	while (current != NULL)
	{
		newNode = current->next;
		current->next = newNode->next;

		if (current->next != NULL)
			newNode->next = current->next->next;

		current = current->next;

		if (newHead == NULL)
			newHead = newNode;
	}

	return newHead;
}

int main()
{
	RandomListNode a(-1);
	a.next = NULL;
	a.random = NULL;

	RandomListNode* result = copyRandomList(&a);

    return 0;
}

