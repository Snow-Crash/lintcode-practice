# 124. Binary Tree Maximum Path Sum

<https://leetcode.com/problems/binary-tree-maximum-path-sum/>

## Solution

```cpp
class Solution {
public:
    int maxPathSum(TreeNode* root) {

        int maxSum = INT_MIN;

        sumPath(root, maxSum);

        return maxSum;
    }

    int sumPath(TreeNode* node, int &maxSum)
    {
        if (node == NULL)
            return 0;

        int val = node->val;

        int left = max(0, sumPath(node->left, maxSum));
        int right = max(0, sumPath(node->right, maxSum));

        maxSum = max(maxSum, val + right + left);

        return val + max(left, right);

    }
};
```

## Reference

<https://www.cnblogs.com/grandyang/p/4280120.html>
