// 2-Sum Problem
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mp;
        int idx=0;
        for(int ele:nums){
            if(mp.find(target - ele)!=mp.end()){
                res.push_back(mp[target-ele]);
                res.push_back(idx);
                break;
            }
            mp[ele]=idx;
            idx++;
        }
        
        return res;
    }
};