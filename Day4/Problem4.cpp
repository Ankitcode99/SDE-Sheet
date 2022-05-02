// Longest subarray with zero sum
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int,int> mp;
        int maxi=0, currSum=0;
        for(int idx=0;idx<n;idx++){
            currSum += A[idx];
            if(currSum==0) maxi=idx+1;
            else{
                if(mp.find(currSum)!=mp.end()){
                    maxi = max(maxi, idx-mp[currSum]);
                }else{
                    mp[currSum] = idx;
                }
            }
        }
        return maxi;
    }
};