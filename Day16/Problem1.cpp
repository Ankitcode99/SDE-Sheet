//Z-Algorithm
class Solution{
public:
	vector<int> calculateZArray(string combined){
	    vector<int> Z(combined.size(),0);
	    int l=0,r=0;
	    for(int k=1;k<combined.size();k++){
	        if(k>r){
	            l=r=k;
	            while(r<combined.size() and combined[r]==combined[r-l]){
	                r++;
	            }
	            Z[k] = r-l;
	            r--;
	        }else{
	            int k1 = k - l;
	            if(k + Z[k1] < r+1)
	                Z[k]=Z[k1];
	            else{
	                l = k;// start a new range from here
	                while(r<combined.size() and combined[r]==combined[r-l]){
	                    r++;
	                }
	                Z[k]=r-l;
	                r--;
	            }
	        }
	    }
	    return Z;
	}

	int zAlgorithm(string s, string p, int n, int m)
	{
		string combined = p+'$'+s;
	    
	    vector<int> zArray = calculateZArray(combined);
	    
	    int cnt=0;
	    for(int idx=0;idx<zArray.size();idx++){
	        if(zArray[idx]==m){
	            cnt++;
	        }
	    }
	    return cnt;
	}
}