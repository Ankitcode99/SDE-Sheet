// Merge 2 sorted arrays with constant space
class Solution {
public:
    
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (int)ceil((n+m)/2.0);
        for(int idx = 0;idx < n;idx++){
            nums1[m+idx] = nums2[idx];
        }
        
        int sz = n+m;
        while(gap>0){
            int idx = 0;
            while(idx+gap<sz){
                if(nums1[idx] > nums1[idx+gap]){
                    swap(nums1[idx],nums1[idx+gap]);
                }
                idx++;
            }
            if(gap==1) break;
            gap = (int)ceil(gap/2.0);
        }
    }
};