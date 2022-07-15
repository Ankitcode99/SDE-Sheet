//Zig Zag level order Traversal
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int leftToRight = 1;
        while(q.size()){
            int sizee = q.size();
            vector<int> row(sizee);
            for(int i=0;i<sizee;i++){
                TreeNode* temp = q.front();
                q.pop();
                int idx = leftToRight ? i : sizee-i-1;
                row[idx] = temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(row);
            leftToRight ^= 1;
        }
        return ans;
    }
};