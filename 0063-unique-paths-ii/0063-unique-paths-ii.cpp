class Solution {
private:
    int f(vector<vector<int>>& obstacles, int row, int col, vector<vector<int>>& dp){
        if(row<0 || col<0 || obstacles[row][col]==1) return 0;
        if(row==0&&col==0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = f(obstacles,row-1,col,dp);
        int left = f(obstacles,row,col-1,dp);
        return dp[row][col]=up+left; 
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(obstacleGrid,n-1,m-1,dp);
    }
};