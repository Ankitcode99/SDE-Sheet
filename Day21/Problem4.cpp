//Design a BST Iterator
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    void pushLeft(TreeNode* root){
        TreeNode* curr = root;
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        
        pushLeft(temp->right);
        return temp->val;
        
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};