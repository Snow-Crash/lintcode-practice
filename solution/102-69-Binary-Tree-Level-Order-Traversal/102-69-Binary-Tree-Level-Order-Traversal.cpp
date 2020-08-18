// 102-69-Binary-Tree-Level-Order-Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == NULL)
            return {};

        vector<vector<int>> result;

        queue<TreeNode*> q;

        q.push(root);

        while (q.empty() == false)
        {
            int q_size = q.size();

            vector<int> level;

            for (int i = 0; i < q_size; i++)
            {
                TreeNode* node = q.front();

                level.push_back(node->val);

                q.pop();

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
