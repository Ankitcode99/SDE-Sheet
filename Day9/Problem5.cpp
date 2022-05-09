//Palindrome Partition
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,curr,ans,s);
        return ans;
    }
    void solve(int idx,vector<string>& curr,vector<vector<string>>& ans, string s){
        if(idx==s.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(i+1,curr,ans,s);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};