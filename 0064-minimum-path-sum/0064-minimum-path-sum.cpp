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
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(grid,n-1,m-1,dp);
    }
};