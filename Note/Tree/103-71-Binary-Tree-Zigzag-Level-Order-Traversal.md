# Binary Tree Zigzag Level Order Traversal

<https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/>

<https://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal/>

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == NULL)
            return {};

        queue<TreeNode*> q;

        vector<vector<int>> result;

        q.push(root);

        int l = 0;

        while(q.empty() == false)
        {
            int q_size = q.size();

            vector<int> level;

            for(int i = 0; i < q_size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            if (l % 2 == 0)
                result.push_back(level);
            else
                result.push_back(vector<int>(level.rbegin(), level.rend()));

            l++;
        }

        return result;

    }
};
```
