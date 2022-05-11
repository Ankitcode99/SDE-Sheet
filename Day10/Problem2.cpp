// N-Queens Problem
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> currBoard(n);
        string s(n,'.');
        for(int i=0;i<n;i++) currBoard[i]=s;
        vector<bool> rowLeft(n,0), leftDiag(2*n-1,0), rightDiag(2*n-1,0);
        solve(0,currBoard,ans,rowLeft,leftDiag,rightDiag,n);
        return ans;
    }
    
    void solve(int col,vector<string>& currBoard,vector<vector<string>>& ans,vector<bool> rowLeft,vector<bool> leftDiag,vector<bool> rightDiag,int n){
        if(col==n){
            ans.push_back(currBoard);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(rowLeft[row]==0 && leftDiag[row+col]==0 && rightDiag[n-1+col-row]==0){
                currBoard[row][col]='Q';
                rowLeft[row]=1;
                leftDiag[row+col]=1;
                rightDiag[n-1+col-row]=1;
                solve(col+1,currBoard,ans,rowLeft,leftDiag,rightDiag,n);
                rightDiag[n-1+col-row]=0;
                leftDiag[row+col]=0;
                rowLeft[row]=0;
                currBoard[row][col]='.';
            }
        }
    }
};