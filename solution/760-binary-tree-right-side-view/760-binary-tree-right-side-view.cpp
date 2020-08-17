// 760-binary-tree-right-side-view.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/binary-tree-right-side-view/description
// ref: https://www.cnblogs.com/grandyang/p/4051321.html
// ref: https://www.cnblogs.com/grandyang/p/4392254.html

#include <iostream>
#include <vector>
#include <queue>

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
     * @param root: the root of the given tree
     * @return: the values of the nodes you can see ordered from top to bottom
     */
    vector<int> rightSideView(TreeNode* root) {
        // write your code here

        vector<int> rightView;

        vector<vector<int>> traversal = LevelOrderTraverse(root);

        for (int i = 0; i != traversal.size(); i++)
        {
            int len = traversal[i].size();
            rightView.push_back(traversal[i][len - 1]);
        }

        return rightView;
    }


    vector<vector<int>> LevelOrderTraverse(TreeNode* root)
    {

        if (root == NULL)
            return {};

        std::queue<TreeNode*> q;

        vector<vector<int>> result;

        q.push(root);

        while (q.empty() == false)
        {
            int q_size = q.size();

            vector<int> level;


            for (int i = 0; i != q_size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
