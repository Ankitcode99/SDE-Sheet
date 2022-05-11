// Print all permutations
class Solution {
public:
    void solve(map<int,int>& mp,vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1){
                curr.push_back(nums[i]);
                mp[nums[i]]=0;
                solve(mp,curr,ans,nums);
                mp[nums[i]]=1;
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,int> mp;
        for(int ele:nums) mp[ele]=1;
        vector<vector<int>> ans;
        vector<int> curr;
        solve(mp,curr,ans,nums);
        return ans;
    }
};