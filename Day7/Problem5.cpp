//Remove duplicates from sorted array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz==0 or sz==1) return sz;
        
        int idx=1;
        for(int ptr=1;ptr<sz;ptr++){
            if(nums[ptr]!=nums[idx-1]){
                nums[idx]=nums[ptr];
                idx++;
            }
        }
        return idx;
    }
};