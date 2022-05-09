//Subset Sums
class Solution
{
public:
    
    void solve(int idx, int sum,vector<int> arr,vector<int>& ans,int N){
        if(idx==N){
            ans.push_back(sum);
            return;
        }
        solve(idx+1,sum,arr,ans,N);
        solve(idx+1,sum+arr[idx],arr,ans,N);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(0,0,arr,ans,N);
        return ans;
    }
};