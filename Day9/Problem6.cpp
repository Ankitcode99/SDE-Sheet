// k'th Permutation Sequence
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact=1;
        for(int i=1;i<=n;i++){
            fact *= i;
            nums.push_back(i);
        }
        k-=1;
        fact/=nums.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + (k/fact));
            if(nums.size()==0) break;
            k=k%fact;
            fact/=nums.size();
        }
        return ans;
    }
};