// 67- Binary-Tree-Inorder-Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode* root) {
        // write your code here

        vector<int> result;

        stack<TreeNode*> stk;

        if (root == NULL)
            return {};

        TreeNode* node = root;

        while (stk.empty() == false || node != NULL)
        {
            while (node != NULL)
            {
                stk.push(node);
                node = node->left;
            }

            node = stk.top();

            stk.pop();

            result.push_back(node->val);

            node = node->right;

        }
        return result;
    }
};

int main()
{

    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);

    n1.left = &n2;
    n1.right = &n3;

    Solution solution;

    vector<int> res = solution.inorderTraversal(&n1);
}