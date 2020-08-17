// 1105-print-binary-tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>
#include <queue>
#include <string>

using namespace std;

//Definition of TreeNode:
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
     * @param root: the given tree
     * @return: the binary tree in an m*n 2D string array
     */
    vector<vector<string>> printTree(TreeNode* root) {
        // Write your code here


        if (root == NULL)
            return {};

        vector<tuple<TreeNode*, int, int, int>> list = traversal(root);

        int depth = get<3>(list.back());

        int width = pow(2, depth - 1);

        int half_width = width / 2;

        if (width > 1)
            width += 1;

        cout << width;

        vector<vector<string>> result(depth, vector<string>(width, ""));

        for (int i = 0; i != list.size(); i++)
        {
            int pos = get<2>(list[i]);
            int d = get<3>(list[i]) - 1;
            TreeNode* node = get<0>(list[i]);

            // cout << d;

            result[d][half_width - d + pos] = to_string(node->val);
        }

        return result;

    }

    // idx, pos in row, depth
    vector<tuple<TreeNode*, int, int, int>> traversal(TreeNode* root)
    {
        std::queue<tuple<TreeNode*, int, int, int>> q;

        q.push(make_tuple(root, 1, 0, 1));

        vector<tuple<TreeNode*, int, int, int>> result;

        while (q.empty() == false)
        {
            int q_size = q.size();

            for (int i = 0; i != q_size; i++)
            {
                TreeNode* node = get<0>(q.front());
                int idx = get<1>(q.front());
                int pos = get<2>(q.front());
                int depth = get<3>(q.front());

                int next_level_width = pow(2, depth);

                result.push_back(q.front());

                q.pop();

                if (node->left != NULL)
                {
                    tuple <TreeNode*, int, int, int> left;

                    left = make_tuple(node->left, idx * 2, idx * 2 - next_level_width, depth + 1);

                    q.push(left);
                }

                if (node->right != NULL)
                {
                    tuple <TreeNode*, int, int, int> right;

                    right = make_tuple(node->right, idx * 2 + 1, idx * 2 + 1 - next_level_width, depth + 1);

                    q.push(right);
                }
            }
        }

        return result;

    }
};

int main()
{
    std::cout << "Hello World!\n";

    TreeNode node1(5);
    TreeNode node2(2);
    TreeNode node3(-3);

    node1.left = &node2;
    node1.right = &node3;

    

    Solution solution;

    vector<vector<string>> result = solution.printTree(&node1);


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
