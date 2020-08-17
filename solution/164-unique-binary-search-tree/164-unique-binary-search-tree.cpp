// 164-unique-binary-search-tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/unique-binary-search-trees-ii/description
// ref: https://www.cnblogs.com/grandyang/p/4301096.html

#include <iostream>
#include <vector>

using namespace std;

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
}

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode*> generateTrees(int n) {
        // write your code here

        vector<TreeNode*> result = dfs(1, n);

        return result;
    }

    vector<TreeNode*> dfs(int start, int end)
    {
        if (start > end)
        {
            vector<TreeNode*> result = { NULL };
            return result;
        }

        vector<TreeNode*> trees;

        for (int root = start; root <= end; root++)
        {
            vector<TreeNode*> left = dfs(start, root - 1);
            vector<TreeNode*> right = dfs(root + 1, end);

            for (int i = 0; i != left.size(); i++)
                for (int j = 0; j != right.size(); j++)
                {
                    TreeNode* currentNode = new TreeNode(root);
                    currentNode->left = left[i];
                    currentNode->right = right[j];
                    trees.push_back(currentNode);
                }
        }

        return trees;
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
