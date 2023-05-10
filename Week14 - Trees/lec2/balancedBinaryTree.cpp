// https://leetcode.com/problems/balanced-binary-tree/
class Solution {
public:
    int height(TreeNode* root) {
        if(root==NULL)
            return 0;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int ans=max(leftHeight,rightHeight)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        //base case-> tree is empty
        if(root==NULL){
            return true;
        }
        //solve 1 case
        int lh=height(root->left);
        int rh=height(root->right);
        int diff=abs(lh-rh);
        bool ans1=(diff<=1);
        //recursion
        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);
        if(ans1&&leftAns&&rightAns){
            return true;
        }else{
            return false;
        }

    }
};