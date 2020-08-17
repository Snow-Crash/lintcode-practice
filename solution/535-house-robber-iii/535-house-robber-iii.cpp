// 535-house-robber-iii.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/house-robber-iii/description
// ref: https://www.cnblogs.com/grandyang/p/5275096.html

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here

        unordered_map<TreeNode*, int> money;

        int result = dfs(root, money);

        return result;
    }

    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& money)
    {

        if (root == NULL)
        {
            return 0;
        }

        if (money.find(root) != money.end())
            return money[root];

        //calculate money of robbing current TreeNode
        // so skip its child. of money will not depend on its chils
        int value = root->val;
        if (root->left != NULL)
        {
            value = value + dfs(root->left->left, money);
            value = value + dfs(root->left->right, money);
        }

        if (root->right != NULL)
        {
            value += dfs(root->right->left, money);
            value += dfs(root->right->right, money);
        }

        //calculate value of not robbing current node, so money depends on its child
        int value2 = 0;
        value2 += dfs(root->left, money);
        value2 += dfs(root->right, money);

        int result = max(value, value2);

        money[root] = result;

        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}