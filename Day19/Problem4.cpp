//Flatten binary tree to linked list
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* temp=curr->left;
                while(temp->right){
                    temp=temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left=NULL;
            }
            curr = curr->right;
        }
    }
};