//Floor in a BST
class Solution{
public:
    void solve(TreeNode<int>* root,int X, int& ans){
        if(!root) return;
        
        if(root->val <= X){
            ans = max(ans,root->val);
        }
        
        if(root->val > X){
            solve(root->left,X,ans);
        }else{
            solve(root->right,X,ans);
        }
    }
    int floorInBST(TreeNode<int> * root, int X)
    {
        int ans=-1;
        solve(root,X,ans);
        return ans;
    }
}