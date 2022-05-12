// Element which appears once while others appear twice
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<hi)
        {
            int mid = lo + (hi-lo)/2;
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    lo=mid+2;
                }
                else
                {
                    hi=mid;
                }
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                {
                    lo=mid+1;
                }
                else
                {
                    hi=mid-1;
                }
            }
        }
        return nums[lo];
    }
};