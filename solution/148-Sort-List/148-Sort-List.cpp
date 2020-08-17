// 148-Sort-List.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sort-list/
// https://www.lintcode.com/problem/sort-list/description

#include <stddef.h>

using namespace std;

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
    ListNode* sortList(ListNode* head) {

        ListNode* h = sort(head);

        return h;
    }

    ListNode* sort(ListNode* head)
    {
        if (head == NULL)
            return head;
        else if (head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* h1 = sort(head);
        ListNode* h2 = sort(second);

        ListNode* merged = merge(h1, h2);

        return merged;
    }

    ListNode* merge(ListNode* h1, ListNode* h2)
    {
        ListNode* p1 = h1;
        ListNode* p2 = h2;

        ListNode dummy(-1);
        ListNode* current = &dummy;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val > p2->val)
            {
                current->next = p2;
                p2 = p2->next;
            }
            else
            {
                current->next = p1;
                p1 = p1->next;
            }

            current = current->next;
        }

        if (p1 == NULL)
        {
            current->next = p2;
        }
        else
        {
            current->next = p1;
        }

        return dummy.next;
    }
};

int main()
{
    // test case 1
    
    ListNode n1(4);
    ListNode n2(2);
    ListNode n3(1);
    ListNode n4(3);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution solution;

    ListNode* head = solution.sortList(&n1);

}
