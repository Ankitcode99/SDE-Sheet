class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int mx=INT_MIN, mxProfit=0;
        for(int i=sz-1;i>=0;i--){
            if(i!=sz-1 and prices[i]<mx){
                mxProfit = max(mxProfit,mx-prices[i]);
            }
            mx = max(mx,prices[i]);
        }
        return mxProfit;
    }
};