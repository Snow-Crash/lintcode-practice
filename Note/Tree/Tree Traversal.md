# Tree Traversal

In-order: Left -> root -> right

Pre-order: Root -> left -> right

Post-order: left -> right -> right

## In-order Traversal

### Recursive Verion

```cpp
void inorder(TreeNode* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->val;
    inorder(left->right);
}
```

### Iterative Version

<https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/>

```cpp
void inorder(TreeNode* root)
{
    stack<TreeNode *> s;
    Node *curr = root;

    while(curr != NULL && s.empty() == false)
    {
        while(current != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        // curr is NULL, assign stack top to curr
        // this is the left most node in current sub tree
        curr = s.top();
        s.pop();

        cout << curr->val;
        curr = curr->right;
    }
}
```

## Pre order Traversal

### Recursive Version

```cpp
void preorder(TreeNode* node)
{
    if (node == NULL)
        return;

    // visit curret node first
    cout << node->val;

    preorder(node->left);

    preorder(node->right);
}
```

### Iterative version

<https://www.geeksforgeeks.org/iterative-preorder-traversal/>

```cpp
void preorder(TreeNode* root)
{
    if (root == NULL)
        return;

    stack <TreeNode*> s;
    s.push(root);

    while(s.empty() == false)
    {
        TreeNode* node = s.top();
        s.pop();
        cout << node->val;

        if (node->right != NULL)
            s.push(node->right);

        if (node->left != NULL)
            s.push(node->left);
    }
}
```

## Post-order Traversal

### Recursive Version

```cpp
void postorder(TreeNode* node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);

    cout << node->val;
}
```

### Iterative Version

Todo

## Level Order Traversal

```cpp
void levelorder(TreeNode* root)
{
    if (root == NULL)
        return;

    queue<TreeNode*> q;

    q.push(root);

    while(q.empty() == false)
    {
        int q_size = q.size();

        for(int i = 0; i < q.size(); i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);
        }
    }
}


```
