// Word Break (Print all ways)
class Solution {
public:
    
    set<string> dict;
    vector<string> ans;
    
    void solve(string s,string curr)
    {
        if(s.size()==0)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=0;i<s.size();i++)
        {
            string left = s.substr(0,i+1);
            if(dict.find(left)!=dict.end())
            {
                string right = s.substr(i+1);
                string sp="";
                if(right.size())
                    sp=" ";
                solve(right,curr+left+sp);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict)
        {
            dict.insert(x);
        }
        string temp="";
        solve(s,temp);
        
        return ans;        
    }
};