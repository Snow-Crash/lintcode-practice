# Binary Tree Level Order Traversal

<https://leetcode.com/problems/binary-tree-level-order-traversal/>
<https://www.lintcode.com/problem/binary-tree-level-order-traversal/>

# Key points

Queue

## Solution

```cpp
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
```