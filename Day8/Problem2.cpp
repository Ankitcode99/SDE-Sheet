// Minimum platforms
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n){
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=0,j=0;
    	int cnt=0, maxi=0;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        cnt++;
    	        maxi=max(maxi,cnt);
    	        i++;
    	    }else{
    	        cnt--;
    	        j++;
    	    }
    	}
    	return maxi;
    }
};