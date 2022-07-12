//Reverse words in a string
class Solution {
public:
    string reverseWords(string s) {
        int sz = s.size();
        int start=-1,end=-1;
        for(int i=0;i<sz;i++){
            if(s[i]!=' '){
                start=i;
                break;
            }
        }
        for(int i=sz-1;i>=0;i--){
            if(s[i]!=' '){
                end=i;
                break;
            }
        }
        s=s.substr(start,end-start+1);
        
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                while(s[i+1]==' '){
                    s.erase(i+1,1);
                }
            }
        }
        
        string ans="",temp="";
        s+=" ";
        for(char x:s){
            if(x!=' '){
                temp+=x;
            }else{
                if(ans=="")
                    ans=temp;
                else
                    ans=temp+" "+ans;
                temp="";
            }
        }
        return ans;
    }
};