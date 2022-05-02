// Count of subarrays with XOR k
class Solution{
public:
	int solve(vector<int> &A, int B) {
	    map<int,int> mp;
	    int currXor = 0, cnt=0;
	    for(int ele: A){
	        currXor ^= ele;
	        if(currXor == B){
	            cnt++;
	        }

	        int other = B ^ currXor;
	        if(mp.find(other)!=mp.end()){
	            cnt += mp[other];
	        }

	        mp[currXor]++;
	    }
	    return cnt;
	}

};