// Height Balanced Binary Tree
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced=true;
        height(root,balanced);
        return balanced;
    }
    int height(TreeNode* root,bool& balanced){
        if(!root)
            return 0;
        
        int left = height(root->left,balanced);
        int right = height(root->right,balanced);
        
        if(abs(left-right)>1)
            balanced = false;
        
        return 1+max(left,right);
    }
};