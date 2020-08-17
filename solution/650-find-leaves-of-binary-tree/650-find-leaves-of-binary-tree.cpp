// 650-find-leaves-of-binary-tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode* root) {
        // write your code here

        vector<vector<int>> result;

        dfs(root, result);

        return result;
    }

    int dfs(TreeNode* root, vector<vector<int>>& result)
    {
        if (root == NULL)
            return 0;

        int left_hight = dfs(root->left, result);
        int right_hight = dfs(root->right, result);

        int depth = 1 + max(left_hight, right_hight);

        if (depth > result.size())
            result.resize(depth);

        result[depth - 1].push_back(root->val);

        return depth;
    }

};

int main()
{
    std::cout << "Hello World!\n";
}
