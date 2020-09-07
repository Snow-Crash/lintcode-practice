// 25-reverse-nodes-in-k-group.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int cnt = 0;

        ListNode* end = head;

        while (cnt < k && end != NULL)
        {
            end = end->next;
            cnt++;
        }

        if (cnt == k)
        {
            ListNode* reversed_head = reverse(head, k);

            //now head becomes tail
            //let tail->next point to next segment
            //next points to the next node of current segment
            ListNode* next_head = reverseKGroup(end, k);

            head->next = next_head;

            return reversed_head;

        }
        else
        {
            return head;
        }
    }

    ListNode* reverse(ListNode* head, int k)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;

        for (int i = 0; i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        int cnt = 0;

        ListNode dummy(-1);

        ListNode* curr = head;

        ListNode* start = head;

        ListNode* tail = &dummy;

        while (curr != NULL)
        {
            cnt = 0;

            while (curr != NULL && cnt < k)
            {
                curr = curr->next;
                cnt++;
            }

            if (cnt % k == 0)
            {
                //reverse
                ListNode* reversed_head = reverse(start, k);

                tail->next = reversed_head;

                //start becomes end
                tail = start;

                //curr points to the first node of next segment
                start = curr;

            }
            else
            {
                tail->next = start;
            }
        }
    
        
        return dummy.next;

    }

    ListNode* reverse(ListNode* head, int k)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;

        for (int i = 0; i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main()
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;


    Solution2 solution;

    ListNode* head = solution.reverseKGroup(&l1, 2);

}
