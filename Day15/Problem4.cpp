//String to Integer
class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        int res=0, start=0, sz=s.size();
        
        while(start<sz and s[start]==' ') start++;
        
        if(start<sz and s[start]=='+') sign=1,start++;
        else if(start<sz and s[start]=='-') sign=-1,start++;
        
        while(start<sz and (s[start]>='0' and s[start]<='9')){
            int dig=s[start]-'0';
            
            if((res > INT_MAX/10) || (res==INT_MAX/10 and dig > INT_MAX%10)){
                return sign==1 ? INT_MAX : INT_MIN;
            }
            
            res = res*10 + dig;
            start++;
        }
        
        return res*sign;
    }
};