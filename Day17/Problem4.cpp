//Morris Inorder Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans={};
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* pre = curr->left;
                while(pre->right!=NULL and pre->right!=curr){
                    pre=pre->right;
                }
                
                if(pre->right==NULL){
                    pre->right=curr;
                    curr=curr->left;
                }else{
                    pre->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};