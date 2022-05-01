// Majority Element (> N/3)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=0,num2=0, count1=0, count2=0;
        
        for(int ele: nums){
            if(ele==num1){
                count1++;
            }else if(ele==num2){
                count2++;
            }else if(count1==0){
                num1 = ele;
                count1 = 1;
            }else if(count2==0){
                num2 = ele;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        
        int sz = nums.size();
        count1=0, count2=0;
        
        for(int ele:nums){
            if(ele == num1) count1++;
            
            if(ele == num2) count2++;
        }
        
        vector<int> ans;
        if(count1>(sz/3)) ans.push_back(num1);
        if(count2>(sz/3) and num1!=num2) ans.push_back(num2);
        
        return ans;
    }
};