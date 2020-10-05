# 236. Lowest Common Ancestor of a Binary Tree

<https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/>

## Summary

Recursively visit left child and right child. Returns true if current node is p or q, or its left or right subtree contains one of p and q.

Case 1. If a node's left subtree returns true and right subtree also returns true, this will be the least common ancestor.

Case 2. If a node's left subtree or right subtree contains one of p and q, and current node is one of p and q, current node is the least common ancestor.

## Solution

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ancestor = NULL;

        recursion(root, p, q, ancestor);

        return ancestor;
    }

    bool recursion(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ancestor)
    {
        if (root == NULL)
            return false;

        bool left = recursion(root->left, p, q, ancestor);

        bool right = recursion(root->right, p, q, ancestor);

        bool current = ((root == p) || (root == q));

        if (left && right)
            ancestor = root;

        if (current && (left || right))
            ancestor = root;

        return left || right || current;
    }
};
```
