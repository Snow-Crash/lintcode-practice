// 21-Merge-Two-Sorted-Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy(-1);

        ListNode* p = &dummy;

        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val <= p2->val)
            {
                ListNode* node = new ListNode(p1->val);
                p->next = node;
                p1 = p1->next;
            }
            else
            {
                ListNode* node = new ListNode(p2->val);
                p->next = node;
                p2 = p2->next;
            }
            p = p->next;
        }

        ListNode* n = (p1 != NULL) ? p1 : p2;

        while (n != NULL)
        {
            ListNode* node = new ListNode(n->val);
            p->next = node;
            p = p->next;
            n = n->next;
        }

        return dummy.next;
    }
};

int main()
{
    ListNode n1(-9);
    ListNode n2(3);
    ListNode p1(5);
    ListNode p2(7);

    n1.next = &n2;
    p1.next = &p2;

    Solution solution;
    ListNode* res = solution.mergeTwoLists(&n1, &p1);

}