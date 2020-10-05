# 101.Symmetric Tree

<https://leetcode.com/problems/symmetric-tree>

## Summary

## Solution 1

Iterative level order traversal. Use two queues, one iterate from left to right, another one iterate from right to left. Every time get top element from the two queues respectively. And then compare the two node. If they are not equal (one is NULL, the other one is not, or values are different). Even if a node's child is NULL, still need to push NULL to the queue.

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        queue<TreeNode*> l2r;
        queue<TreeNode*> r2l;

        if (root == NULL)
            return true;

        l2r.push(root);
        r2l.push(root);

        while(l2r.empty() == false)
        {  

            int l_size = l2r.size();
            int r_size = r2l.size();

            if (l_size != r_size)
                return false;

            for(int i = 0; i < l_size; i++)
            {

                TreeNode* l = l2r.front();
                TreeNode* r = r2l.front();

                l2r.pop();
                r2l.pop();

                if (l == NULL && r == NULL)
                    continue;
                else if(l == NULL && r != NULL)
                    return false;
                else if (l != NULL && r == NULL)
                    return false;

                if (l->val != r->val)
                    return false;

                    l2r.push(l->left);
                    l2r.push(l->right);
                    r2l.push(r->right);
                    r2l.push(r->left);
            }
        }

        return true;
    }
};
```

## Solution 2

Recursive. 

<https://www.cnblogs.com/grandyang/p/4051715.html>

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;

        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right)
        return true;

        if (left && !right || !left && right || left->val != right->val)
            return false;

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};
```
