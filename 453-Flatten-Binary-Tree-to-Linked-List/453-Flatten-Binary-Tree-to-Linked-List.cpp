// 453-Flatten-Binary-Tree-to-Linked-List.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/flatten-binary-tree-to-linked-list/description
// ref: https://www.cnblogs.com/grandyang/p/4293853.html

#include <iostream>

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode* root) {
        // write your code here

        if (root == NULL)
            return;

        std::stack<TreeNode*> stack;

        stack.push(root);

        while (stack.empty() == false)
        {

            TreeNode* current = stack.top();
            stack.pop();

            if (current->left != NULL)
            {
                TreeNode* right = current->left;

                // find the right most node under current node's left sub tree
                while (right->right != NULL)
                {
                    right = right->right;
                }

                //move right sub tree of current to right of right
                right->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }

            if (current->right != NULL)
                stack.push(current->right);
        }
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
