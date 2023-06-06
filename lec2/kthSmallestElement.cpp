// question:- https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution
{
public:
    int kthSmallest(TreeNode *root, int &k)
    {
        // base case
        if (root == NULL)
        {
            return -1;
        }
        // Inorder
        // left
        int leftAns = kthSmallest(root->left, k);

        if (leftAns != -1)
            return leftAns;

        // N -> root
        k--;
        if (k == 0)
        {
            return root->val;
        }

        // right
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
    }
};
