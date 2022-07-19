//Ceil in a BST
class Solution{
public:
	void solve(BinaryTreeNode<int>* root,int X,int& ans){
	    if(!root) return;
	    
	    if(root->data >= X){
	        ans = min(ans,root->data);
	    }
	    
	    if(root->data < X){
	        solve(root->right,X,ans);
	    }else{
	        solve(root->left,X,ans);
	    }
	}
	int findCeil(BinaryTreeNode<int> *node, int x){
	    int ans=INT_MAX;
	    solve(node,x,ans);
	    return ans==INT_MAX ? -1 : ans;
	}
};