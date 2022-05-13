//Allocate minimum pages
class Solution{
public:
	bool isPossible(vector<int>& ar,int b,int mid){
	    int sum=0;
	    int student=0;
	    for(int i=0;i<ar.size();i++){
	        if(sum+ar[i]>mid){
	            student++;
	            sum=ar[i];
	            if(sum>mid){
	                return false;
	            }
	        }else{
	            sum+=ar[i];
	        }
	    }
	    return student<b;
	}

	int books(vector<int> &A, int B) {
	    if(A.size()<B) return -1;

	    int low = INT_MAX;
	    int tot=0;
	    for(int page:A){ 
	        low=min(low,page);
	        tot+=page;
	    }
	    int hi=tot;

	    int ans=INT_MAX;
	    while(low<=hi){
	        int mid = (low+hi+1)/2;
	        if(isPossible(A,B,mid)){
	            ans = min(ans,mid);
	            hi=mid-1;
	        }else{
	            low=mid+1;
	        }
	    }
	    return ans;
	}
};