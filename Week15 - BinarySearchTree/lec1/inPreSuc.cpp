// gfg question link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
Node *inPre(Node *root)
{
    Node *p = root->left;
    while (p->right)
        p = p->right;
    return p;
}
Node *inSuc(Node *root)
{
    Node *p = root->right;
    while (p->left)
        p = p->left;
    return p;
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Your code goes here
    if (!root)
        return;
    if (root->key == key)
    {
        if (root->left)
            pre = inPre(root);
        if (root->right)
            suc = inSuc(root);
        return;
    }
    if (key > root->key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if (key < root->key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}