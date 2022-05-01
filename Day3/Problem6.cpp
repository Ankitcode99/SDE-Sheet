// Reverse Pairs
class Solution {
public:
    
    int merge(vector<int>& ar, int low, int mid, int high){
        int invCnt=0;
        int j = mid+1;
        
        for(int i=low;i<=mid;i++){
            while(j<=high && ar[i]>2LL*ar[j]){
                j++;
            }
            invCnt += (j-(mid+1));
        }
        
        vector<int> t;
        int left = low, right = mid + 1;

          while (left <= mid && right <= high) {

            if (ar[left] <= ar[right]) {
                t.push_back(ar[left++]);
            } else {
                t.push_back(ar[right++]);
            }
          }
        
        while(left<=mid) t.push_back(ar[left++]);
        
        while(right<=high) t.push_back(ar[right++]);
        
        for(int idx=low;idx<=high;idx++) ar[idx] = t[idx-low];
        
        return invCnt;
    }
    
    int mergeSort(vector<int>& ar, int left, int right){
        int mid,inversionCnt=0;
        if(right > left){
            mid = (left+right)/2;
            
            inversionCnt += mergeSort(ar,left,mid);
            inversionCnt += mergeSort(ar,mid+1,right);
            
            inversionCnt += merge(ar,left,mid,right);
        }
        return inversionCnt;
    }
    int reversePairs(vector<int>& nums) {
        int sz=nums.size();
        
        return mergeSort(nums,0,sz-1);
    }
};