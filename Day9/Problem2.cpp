// Print all subsets
class Solution {
public:
    
    void solve(int idx,vector<int>& curr,set<vector<int>>& ans, vector<int>& nums){
        if(idx==nums.size()){
            ans.insert(curr);
            return;
        }
        
        solve(idx+1,curr,ans,nums);
        curr.push_back(nums[idx]);
        solve(idx+1,curr,ans,nums);
        curr.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,curr,ans,nums);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
};