class Solution {
    int f(int row, int col, vector<vector<int>>&dp){
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int left = f(row, col-1,dp);
        int top = f(row-1,col,dp);
        return dp[row][col]=left+top;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};