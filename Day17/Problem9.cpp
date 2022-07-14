//Root to node path
class Solution{
public:
	bool recurse(TreeNode* root, int v, vector<int>& ar){
	    if(!root) return false;
	     
	    ar.push_back(root->val);
	     
	    if(root->val==v)
	        return true;
	     
	    if(recurse(root->left,v,ar) || recurse(root->right,v,ar))
	        return true;
	        
	    ar.pop_back();
	    return false;
	 }
	vector<int> solve(TreeNode* root, int v) {
	    vector<int> ans;
	    recurse(root,v,ans);
	    return ans;
	}
}