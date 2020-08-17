// 453-Flatten-Binary-Tree-to-Linked-List.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/flatten-binary-tree-to-linked-list/description
// ref: https://www.cnblogs.com/grandyang/p/4293853.html

#include <iostream>
#include <stack>

using namespace std;

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

class Solution2 {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode* root) {
        // write your code here


        if (root == NULL)
            return;

        stack<TreeNode*> s;

        s.push(root);

        TreeNode* head = new TreeNode(0);

        TreeNode* prev = head;

        while (s.empty() == false)
        {
            TreeNode* node = s.top();

            s.pop();

            prev->right = node;

            if (node->right != NULL)
            {
                s.push(node->right);
            }


            if (node->left != NULL)
            {
                s.push(node->left);
            }

            node->left = NULL;
            node->right = NULL;

            prev = node;
        }

        root = head->right;

    }
};

int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);

    t1.left = &t2;
    t1.right = &t5;
    t2.left = &t3;
    t2.right = &t4;
    t5.right = &t6;

    Solution2 solution;
    solution.flatten(&t1);
}
