// 23-Merge-k-Sorted-Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //int l = 0;
        //int r = lists.size() - 1;

        if (lists.size() == 0)
            return NULL;

        ListNode* head = recursion(0, lists.size() - 1, lists);

        return head;

    }

    ListNode* recursion(int i, int j, vector<ListNode*>& lists)
    {
        if (i == j)
            return lists[i];

        int mid = (i + j) / 2;

        ListNode* n1 = recursion(i, mid, lists);
        ListNode* n2 = recursion(mid + 1, j, lists);

        ListNode* merged = merge(n1, n2);

        return merged;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                l2 = l2->next;
                tail->next = l2;
            }

            tail = tail->next;
        }

        if (l1 == NULL)
            tail->next = l2;
        else
            tail->next = l1;

        return dummy.next;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
