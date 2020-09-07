# Reorder List

<https://leetcode.com/problems/reorder-list/>
<https://www.lintcode.com/problem/reorder-list/>

## Key points

Two pointers, reverse linked list

## Solution

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        //reverse
        ListNode* curr = second;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //prev will be the head of reversed second half linked list

        second = prev;

        ListNode* p1 = head;
        ListNode* p2 = second;

        ListNode dummy;
        ListNode* p = &dummy;

        int i = 0;

        while (p1 != NULL && p2 != NULL)
        {
            if (i % 2 == 0)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }

            p = p->next;
            i++;
        }

        if (p1 == NULL)
            p->next = p2;
        else
            p->next = p1;

        head = dummy.next;
    }
};
```
