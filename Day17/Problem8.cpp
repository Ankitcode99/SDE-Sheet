//Vertical Order Traversal
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        while(q.size()){
            auto it=q.front();
            q.pop();
            TreeNode* temp = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            
            mp[vertical][level].insert(temp->val);
            
            if(temp->left!=NULL){
                q.push({temp->left,{vertical-1,level+1}});
            }
            if(temp->right!=NULL){
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto it: mp){
            vector<int> col;
            for(auto level:it.second){
                col.insert(col.end(),level.second.begin(),level.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};