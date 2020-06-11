// 98. Sort List
// https://www.lintcode.com/problem/sort-list/description

#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// merge sort
class Solution1 {
public:
    ListNode* sortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // if length of linked list is 2n, slow points to nth node,
        // if length of linked list is 2n + 1, slow points to n + 1
        
        ListNode* midPoint = slow->next;
        //break the link list at middle point, very important!!
        slow->next = NULL;

        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(midPoint);

        ListNode* res = mergeSort(p1, p2);

        return res;

    }

    ListNode* mergeSort(ListNode* p1, ListNode* p2)
    {
        //if one of the list is empty, no need to compare, return another list
        if (p1 == NULL)
            return p2;
        else if (p2 == NULL)
            return p1;

        ListNode* current1 = p1;
        ListNode* current2 = p2;

        ListNode dummy(-1);
        ListNode* current = &dummy;

        // p1 and p2 are already sorted. So no need to compare a node in one list with all nodes in
        // another list. Start from beginning, use two pointers to indicate the node that will be compared.
        // if current1 < current2, move current1 to result list, no need to compare current1 with rest nodes in
        // p1, as all the rest nodes are greater than current2. and then move current 1 to next position.
        // stop when current1 or current2 is NULL
        while (current1 != NULL && current2 != NULL)
        {
            if (current1->val < current2->val)
            {     
                current->next = current1;
                current1 = current1->next;
            }
            else
            {
                current->next = current2;
                current2 = current2->next;
            }
            current = current->next;
        }
        
        if (current1 == NULL)
            current->next = current2;
        else if (current2 == NULL)
            current->next = current1;

        return dummy.next;
    };
};

int main()
{
    ListNode a(1);
    ListNode b(3);
    ListNode c(2);

    a.next = &b;
    b.next = &c;

    Solution1 solution_1;

    ListNode* res = solution_1.sortList(&a);

    ListNode* p = res;
    while (p != NULL)
    {
        std::cout << p->val << "->";
        p = p->next;
    }

}
