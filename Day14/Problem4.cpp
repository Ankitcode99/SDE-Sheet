//Sliding window maximum
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int sz = nums.size();
        vector<int> ans;
        for(int idx=0;idx<sz;idx++){
            if(dq.size() and dq.front()==idx-k)
                dq.pop_front();
            
            while(dq.size() and nums[dq.back()]<nums[idx])
                dq.pop_back();
            
            dq.push_back(idx);
            if(idx>=k-1)
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};