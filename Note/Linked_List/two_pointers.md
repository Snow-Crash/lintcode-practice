# Two pointers

## Template

### Style 1

```cpp
ListNode *slow = head;
ListNode *fast = head;

while(fast->next != NULL && fast->next->next != NULL)
{
    slow = slow->next;
    fast = fast->next->next;
}
```

### Style 2

```cpp
ListNode *slow = head, *fast = head, *pre = head;
while (fast && fast->next)
{
    pre = slow;
    slow = slow->next;
    fast = fast->next->next;
}
```

## Note

Style 2 jumps one more time than style 1.Therefore, there is one more pointer prev points to the previous node of slow.

## Related problems

### Leetcode

<https://leetcode.com/problems/sort-list/>

### Lintcode

<https://www.lintcode.com/problem/sort-list/description>

## Reference

<https://www.cnblogs.com/grandyang/p/4249905.html>
