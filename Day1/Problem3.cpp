// Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& ar) {
        int n = ar.size();
        
        if(n==1){
            return;
        }
        
        int idx1=n-2;
        while(idx1>=0 and ar[idx1]>=ar[idx1 + 1]){
            idx1--;
        }
        if(idx1 >= 0){
            int idx2 = n-1;
            while(ar[idx2] <= ar[idx1]) idx2--;
            swap(ar[idx1],ar[idx2]);
        }
        
        idx1 += 1;
        n-=1;
        while(idx1<=n){
            swap(ar[idx1],ar[n]);
            idx1++, n--;
        }
    }
};