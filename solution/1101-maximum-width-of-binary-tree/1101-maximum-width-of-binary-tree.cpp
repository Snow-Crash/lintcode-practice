// 1101-maximum-width-of-binary-tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/maximum-width-of-binary-tree/note/221435
// https://www.cnblogs.com/grandyang/p/7538821.html

#include <iostream>
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
     * @param root: the root
     * @return: the maximum width of the given tree
     */
    int widthOfBinaryTree(TreeNode* root) {
        // Write your code here

        int max_width = levelOrderTraversal(root);

        return max_width;

    }

    int levelOrderTraversal(TreeNode* root)
    {
        if (root == NULL)
            return {};

        std::queue<pair<TreeNode*, int>> q;

        q.push({ root, 1 });

        int max_len = 0;

        while (q.empty() == false)
        {
            int q_size = q.size();

            int left = q.front().second;
            int right = left;

            for (int i = 0; i != q_size; i++)
            {
                TreeNode* node = q.front().first;
                int idx = q.front().second;

                right = idx;

                q.pop();

                if (node->left != NULL)
                    q.push({ node->left, idx * 2 });

                if (node->right != NULL)
                    q.push({ node->right, idx * 2 + 1 });

            }

            max_len = max(max_len, right - left + 1);

        }

        return max_len;
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
