//KMP Algorithm
class Solution{
public:
	bool KMP(string s,string pat,vector<int> &pref){
	    int j=0,i=0;
	    while(j<s.size() and i<pat.size()){
	        if(s[j]==pat[i]){
	            j++,i++;
	        }else{
	            while(i>0 and s[j]!=pat[i]){
	                i=pref[i-1];
	            }
	            if(i==0 and s[j]!=pat[i]){
	                j++;
	            }
	        }
	    }
	    return i==pat.size();
	}

	vector<int> generatePrefixArray(string s){
	    int ss = s.size();
	    vector<int> pref(ss,0);
	    int j=0, i = 1;
	    while (i < ss) {
	        if (s[i] == s[j]) {
	            pref[i] = j+1;
	            i++,j++;
	        }else {
	            if (j != 0) {
	                j = pref[j - 1];
	            }
	            else {
	                pref[i] = 0;
	                i++;
	            }
	        }
	    }
	    return pref;
	}
}