// question:- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
class Solution
{
public:
    void storeInorder(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }
    bool findTarget(TreeNode *root, int k)
    {

        vector<int> inorder;
        storeInorder(root, inorder);
        int s = 0;
        int e = inorder.size() - 1;

        while (s < e)
        {
            int sum = inorder[s] + inorder[e];

            if (sum == k)
                return true;

            if (sum > k)
                e--;
            else
                s++;
        }
        return false;
    }
};