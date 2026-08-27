class Solution {
    int f(int row, int col, vector<vector<int>>&dp){
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int left = f(row, col-1,dp);
        int top = f(row-1,col,dp);
        return dp[row][col]=left+top;
    }
    int f_tabulation(int n,int m){
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) dp[i][j] = 0;
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0&&col==0) dp[row][col] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if (row>0) up = dp[row - 1][col];
                    if (col>0) left = dp[row][col - 1];
                    dp[row][col]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        // return f(m-1,n-1,dp);
        return f_tabulation(m,n);
    }
};