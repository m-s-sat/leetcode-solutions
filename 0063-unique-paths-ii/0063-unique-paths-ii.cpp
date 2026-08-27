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
    int f_tabulation(vector<vector<int>>& obstacleGrid){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) dp[i][j]=0;
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(obstacleGrid[row][col]==1) continue;
                if(row==0&&col==0) dp[row][col]=1;
                else{
                    int up=0,left=0;
                    if(row>0) up=dp[row-1][col];
                    if(col>0) left=dp[row][col-1];
                    dp[row][col] = up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(obstacleGrid,n-1,m-1,dp);
        return f_tabulation(obstacleGrid);
    }
};