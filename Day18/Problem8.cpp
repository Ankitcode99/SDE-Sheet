//Print Tree Boundary(Left,Leaf,Right)
class Solution{
public:
	bool isLeaf(TreeNode<int>* node){
	    return (!node->left && !node->right);
	}

	void getLeftBoundary(TreeNode<int>* root,vector<int>& ans){
	    TreeNode<int>* cur=root->left;
	    while (cur) {
	        if (!isLeaf(cur)) ans.push_back(cur -> data);
	        if (cur -> left) cur = cur -> left;
	        else cur = cur -> right;
	    }
	}
	void getRightBoundary(TreeNode<int>* root,vector<int>& ans){
	    TreeNode<int>* cur=root->right;
	    vector < int > tmp;
	    while (cur) {
	        if (!isLeaf(cur)) tmp.push_back(cur -> data);
	        if (cur -> right) cur = cur -> right;
	        else cur = cur -> left;
        }
        for(int i = tmp.size() - 1; i >= 0; --i){
        	ans.push_back(tmp[i]);
        }
	}

	void getLeaves(TreeNode<int>* root,vector<int>& ans){
	    if(isLeaf(root)){
	        ans.push_back(root->data);
	        return;
	    }
	    if(root->left) getLeaves(root->left,ans);
	    if(root->right) getLeaves(root->right,ans);
	}

	vector<int> traverseBoundary(TreeNode<int>* root){
	    if(!root)
	        return {};
	    
	    vector<int> ans;
	    if(!isLeaf(root))
	        ans.push_back(root->data);
	    getLeftBoundary(root,ans);
	    getLeaves(root,ans);
	    getRightBoundary(root,ans);
	    
	    return ans;
	}
}