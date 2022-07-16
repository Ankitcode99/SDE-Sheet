// LCA of 2 nodes in a BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int par = root->val;
        int pval = p->val;
        int qval = q->val;
        
        if(pval>par and qval>par)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(pval<par and qval<par)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else
            return root;
    }
};