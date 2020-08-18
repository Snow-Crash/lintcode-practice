# Sort List

<https://leetcode.com/problems/sort-list/>
<https://www.lintcode.com/problem/sort-list/description>

## Solution

```cpp
class Solution {
public:
ListNode* sortList(ListNode* head) {

    ListNode* h = sort(head);

    return h;
}

ListNode* sort(ListNode* head)
{
    // if head is null or next of head is null, just simply return head
    if (head == NULL)
        return head;
    else if (head->next == NULL)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow is the middle point
    // disconnect at slow, such that the linked list is divided into two linked list. Repeat this procedure recursively, until the linked list is divided into individual nodes and then start to merge.
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

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->val > p2->val)
        {
            current->next = p2;
            p2 = p2->next;
        }
        else
        {
            current->next = p1;
            p1 = p1->next;
        }

        current =current->next;
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
```

## Note

Use a fast point and a slow pointer.

## Related Problems

### Leetcode

### Lintcode

## Reference

<https://www.cnblogs.com/grandyang/p/4249905.html>
