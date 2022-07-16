// Max Path Sum
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mxSum=INT_MIN;
        solve(root,mxSum);
        return mxSum;
    }
    int solve(TreeNode* root,int& mxSum){
        if(!root)
            return 0;
        
        int left = max(solve(root->left,mxSum),0);
        int right = max(solve(root->right,mxSum),0);
        
        mxSum = max(mxSum, left + root->val + right);
        if(left>right) 
            return root->val + left;
        return root->val + right;
    }
};