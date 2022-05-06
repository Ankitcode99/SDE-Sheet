//Minimum coins problem - Greedy
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    sort(coins,coins+M);
	    int ans=0;
	    for(int i=M-1;i>=0;i--){
	        while(V>=coins[i]){
	            V-=coins[i];
	            cout<<coins[i]<<" "<<V<<"\n";
	            ans++;
	        }
	    }
	    return ans;
	} 
	  
};