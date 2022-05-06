// Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int sum=0;
        int left=0, right = sz-1;
        int leftMax=0, rightMax=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftMax){
                    leftMax = height[left];
                }else{
                    sum += (leftMax - height[left]);
                }
                left++;
            }else{
                if(height[right]>=rightMax){
                    rightMax = height[right];
                }else{
                    sum += (rightMax - height[right]);
                }
                right--;
            }
        }
        return sum;
    }
};