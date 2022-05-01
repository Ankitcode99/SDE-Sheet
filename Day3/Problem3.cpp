// Majority Element (> N/2 times)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElem = 0, countMajority = 0;
        
        for(int ele: nums){
            if(countMajority==0){
                majorityElem = ele;
            }
            
            if(ele == majorityElem) countMajority++;
            else countMajority--;
        }
        return majorityElem;
    }
};