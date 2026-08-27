class Solution {
private:
    int f(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp){
        if(row==0 && col==0) return grid[0][0];
        if(row<0||col<0) return 1e9;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = grid[row][col]+f(grid,row-1,col,dp);
        int left = grid[row][col]+f(grid,row,col-1,dp);
        return dp[row][col] = min(up,left);
    }
    int f_tabulation(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) dp[i][j]=0;
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0&&col==0) dp[row][col]=grid[row][col];
                else{
                    int up = 1e9, left=1e9;
                    if(row>0) up = grid[row][col]+dp[row-1][col];
                    if(col>0) left = grid[row][col]+dp[row][col-1];
                    dp[row][col] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(grid,n-1,m-1,dp);
        return f_tabulation(grid);
    }
};