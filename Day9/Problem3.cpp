//Combination Sum (Print all uniques combinations with given sum)
class Solution {
public:
    
    void solve(int idx, int currSum,vector<int>& curr, set<vector<int>>& res,vector<int>& candidates, int target){
        if(currSum>target || idx==candidates.size()){
            return;
        }
        if(currSum==target){
            res.insert(curr);
            return;
        }
        curr.push_back(candidates[idx]);
        solve(idx,currSum+candidates[idx],curr,res,candidates,target);
        curr.pop_back();
        solve(idx+1,currSum,curr,res,candidates,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> curr;
        solve(0,0,curr,res,candidates,target);
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
};