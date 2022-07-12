//Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int sum=mp[s.back()];
        for(int idx = s.size()-2;idx>=0;idx--){
            if(mp[s[idx]]<mp[s[idx+1]]){
                sum -= mp[s[idx]];
            }else{
                sum += mp[s[idx]];
            }
        }
        return sum;
    }
};