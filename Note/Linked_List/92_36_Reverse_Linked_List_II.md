# Reverse Linked List II

<https://leetcode.com/problems/reverse-linked-list-ii/solution/>

<https://www.lintcode.com/problem/reverse-linked-list-ii/description>

## Solution

```cpp
class Solution {
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

    // At this point, start points to the node where reversal starts. prev points to the predecessor of start node, we need to keep this pointer. Because after reversal, we need to reconnect prev to the beginning of the reversed part.

    ListNode* prev2 = NULL;
    ListNode* current = start;

    // standard approach to reverse linked list.
    while (i <= n)
    {
        next = current->next;
        current->next = prev2;
        prev2 = current;
        current = next;
        i++;
    }

    // Reconnect reversed part to the original linked list.

    start->next = current;

    prev->next = prev2;

    return dummy.next;
}
};
```

## Note

The linked list is 0 indexed, therefore add a dummy node as head. The dummy node also helps avoid corner cases.

## Related Problems

### Leetcode

[206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

[92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)

### Lintcode

[35. Reverse Linked List](https://www.lintcode.com/problem/reverse-linked-list/description)

[36. Reverse Linked List II](https://www.lintcode.com/problem/reverse-linked-list-ii/description)
