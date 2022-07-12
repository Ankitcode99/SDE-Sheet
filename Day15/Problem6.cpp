//Rabin Karp
class Solution{
private:
	const int BASE = 31;
	const int MOD = 1e9 + 7;
	/**
		hash("abc") = a*base^2 + b*base + c;
	*/
public:
	vector<int> stringMatch(string &str, string &pat) {
	    int strLength = str.size();
	    int patLength = pat.size();
	    
	    vector<int> pows(patLength,1);
	    for(int i=1;i<patLength;i++){
	        pows[i] = pows[i-1]*1LL*BASE;
	    }
	    int patHash = 0;
	    int rollHash = 0;
	    for(int idx=0;idx<patLength;idx++){
	        patHash = (patHash + (pows[patLength-idx-1]*1LL*(pat[idx]-'A'+1))%MOD)%MOD;
	        rollHash = (rollHash + (pows[patLength-idx-1]*1LL*(str[idx]-'A'+1))%MOD)%MOD;
	    }
	    vector<int> ans;
	    int l=0,r=patLength-1;
	    do{
	        if(patHash==rollHash and str.substr(l,patLength)==pat){
	            ans.push_back(l);
	        }
	        
	        rollHash = (rollHash - (pows[patLength-1]*1LL*(str[l]-'A'+1))%MOD)%MOD;
	        l++,r++;
	        
	        if(r<strLength){
	            rollHash = ((rollHash*1LL*BASE)%MOD + (str[r]-'A'+1)*1LL)%MOD;
	        }
	    }while(r<strLength);
	    return ans;
	}
}