//Count and Say
/**
countAndSay(1)=1;
countAndSay(n)="say" + countAndSay(n-1)
1-> "1"
2-> say "1" -> one 1 -> "11"
3-> say "11" -> two 1 -> "21"
4-> say "21" -> one 2 one 1 -> "1211"
5-> say "1211" -> one 1 one 2 two 1 -> "111221"
*/
class Solution {
public:
    string generate(string s){
        int j=0,i=0;
        string ans="";
        while(i<s.size() and j<s.size()){
            while(i<s.size() and s[i]==s[j]){
                i++;
            }
            int cnt=i-j;
            ans+=to_string(cnt);
            ans+=s[j];
            j=i;
        }
        return ans;
    }
    
    string countAndSay(int n) {
        vector<string> arr(31);
        arr[1]="1";
        for(int i=2;i<31;i++){
            arr[i]=generate(arr[i-1]);
        }
        return arr[n];
    }
};