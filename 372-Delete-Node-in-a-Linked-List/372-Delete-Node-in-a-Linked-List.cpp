// 372-Delete-Node-in-a-Linked-List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

class Solution {
public:
    /*
     * @param node: the node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode* node) {
        // write your code here

        ListNode* slow = node;
        ListNode* fast = node;

        ListNode* prev = node;

        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }


        prev->next = slow->next;
    }
};

int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution solution;

    solution.deleteNode(&n1);
}