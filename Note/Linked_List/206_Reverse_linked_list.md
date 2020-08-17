# Reverse Linked List

https://leetcode.com/problems/reverse-linked-list/

## Solution

```cpp
class Solution {
public:
ListNode* reverseList(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Finally, current points to the next of previous tail, which is NULL, and prev points to the previous tail. Therefore, prev is the new head.
    return prev;
    }
};
```

## Notes


## Related Problems

### Leetcode

[206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

[92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)

### Lintcode

[35. Reverse Linked List](https://www.lintcode.com/problem/reverse-linked-list/description)

[36. Reverse Linked List II](https://www.lintcode.com/problem/reverse-linked-list-ii/description)


## Reference

https://leetcode.com/problems/reverse-linked-list/solution/