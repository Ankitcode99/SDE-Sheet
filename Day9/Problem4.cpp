//Candidate Sum (Same index cannot be used more than once)
class Solution {
public:
    void solve(int idx, int remSum,vector<int>& curr, vector<vector<int>>& res,vector<int>& candidates){
        if(remSum==0){
            res.push_back(curr);
            return;
        }
        
        for(int i = idx;i<candidates.size();i++){
            if(i>idx and candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>remSum) break;
            curr.push_back(candidates[i]);
            solve(i+1,remSum-candidates[i],curr,res,candidates);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(0,target,curr,res,candidates);
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
};
