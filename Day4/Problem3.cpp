// Longest consecutive sequence in an array
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> elements;
        for(int ele:nums) elements.insert(ele);
        
        int maxStreak = 0;
        for(int ele:nums){
            if(!elements.count(ele-1)){
                int currNum = ele;
                int currStreak = 1;
                while(elements.count(currNum+1)){
                    currNum += 1;
                    currStreak += 1;
                }
                maxStreak = max(maxStreak, currStreak);
            }
        }
        return maxStreak;
    }
};