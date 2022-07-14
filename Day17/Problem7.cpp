//All 3 traversals in one go
class Solution{
public:
	vector<vector<int>> getTreeTraversal(TreeNode *root){
	    // Write your code here.
	    vector<int> inorder,preorder,postorder;
	    if(root==NULL) return {};
	    stack< pair<TreeNode* ,int> > st;
	    st.push({root,1});
	    while(st.size()){
	        auto it = st.top();
	        st.pop();
	        if(it.second==1){
	            preorder.push_back(it.first->data);
	            it.second++;
	            st.push(it);
	            if(it.first->left!=NULL){
	                st.push({it.first->left, 1});
	            }
	        }else if(it.second==2){
	            inorder.push_back(it.first->data);
	            it.second++;
	            st.push(it);
	            if(it.first->right!=NULL){
	                st.push({it.first->right, 1});
	            }
	        }else{
	            postorder.push_back(it.first->data);
	        }
	    }
	    vector<vector<int>> ans={inorder,preorder,postorder};
	    return ans;
	}
}