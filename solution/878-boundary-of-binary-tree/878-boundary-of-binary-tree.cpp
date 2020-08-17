// 878-boundary-of-binary-tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
// https://www.lintcode.com/problem/boundary-of-binary-tree/description
// ref: https://www.cnblogs.com/grandyang/p/6833459.html

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
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // write your code here

        vector<int> result;

        if (root == NULL)
            return result;

        if (root->left != NULL || root->right != NULL)
            result.push_back(root->val);

        left(root->left, result);

        leaf(root, result);

        right(root->right, result);

        return result;
    }


    void left(TreeNode* root, vector<int>& result)
    {
        if (root == NULL)
            return;

        // this is leaf
        if (root->left == NULL && root->right == NULL)
            return;

        result.push_back(root->val);

        if (root->left == NULL)
            left(root->right, result);
        else
            left(root->left, result);
    }

    void right(TreeNode* root, vector<int>& result)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            return;

        if (root->right == NULL)
            right(root->left, result);
        else
            right(root->right, result);

        result.push_back(root->val);
    }

    void leaf(TreeNode* root, vector<int>& result)
    {
        if (root == NULL)
            return;

        if (root->left != NULL)
            leaf(root->left, result);

        if (root->right != NULL)
            leaf(root->right, result);

        if (root->left == NULL && root->right == NULL)
            result.push_back(root->val);
    }

};

int main()
{
    std::cout << "Hello World!\n";
}