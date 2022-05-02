// 4 Sum Problem
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz<=3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int idx1=0;idx1<sz;idx1++){
            for(int idx2=idx1+1;idx2<sz;idx2++){
                int remaining = target - nums[idx1] - nums[idx2];
                
                int left = idx2+1, right = sz-1;
                while(left<right){
                    int sum = nums[left] + nums[right];
                    if(sum < remaining) left++;
                    
                    else if(sum > remaining) right--;
                    
                    else{
                        vector<int> quad = {nums[idx1],nums[idx2],nums[left],nums[right]};
                        res.push_back(quad);
                        
                        while(left < right and nums[left]==quad[2]) left++;
                        
                        while(right > left and nums[right]==quad[3]) right--;
                    }
                    
                }
                while(idx2+1<sz and nums[idx2]==nums[idx2+1]) idx2++;
            }
            while(idx1+1<sz and nums[idx1]==nums[idx1+1]) idx1++;
        }
        
        return res;
    }
};