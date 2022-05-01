// Grid Unique Paths
class Solution {
public:
    int solve(int currRow,int currCol, int rows, int cols,vector<vector<int>>& dp){
        if(currRow==rows-1 and currCol==cols-1){
            return 1;
        }
        if(currRow==rows or currCol==cols){
            return 0;
        }
        
        if(dp[currRow][currCol]!=-1) return dp[currRow][currCol];
        
        return dp[currRow][currCol] = solve(currRow+1,currCol,rows,cols,dp) + solve(currRow,currCol+1,rows,cols,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return solve(0,0,m,n,dp);
    }
};