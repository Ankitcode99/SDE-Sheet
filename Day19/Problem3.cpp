//Symmetric Binary Tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return solve(root->left,root->right);
    }
    bool solve(TreeNode* a, TreeNode* b){
        
        if(!a && !b)
            return true;
        
        if(!a or !b)
            return false;
        
        return (a->val==b->val && solve(a->left,b->right) && solve(a->right,b->left));
    }
};