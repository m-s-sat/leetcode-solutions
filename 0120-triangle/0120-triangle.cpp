class Solution {
private:
    int f(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp){
        if(row==0&&col==0) return triangle[row][col];
        if(row<0||col<0||triangle[row].size()<=col) return 1e9;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = triangle[row][col]+f(triangle,row-1,col,dp);
        int diagonal = triangle[row][col]+f(triangle,row-1,col-1,dp);
        return dp[row][col]=min(up,diagonal);
    }
    int f_tabulation(vector<vector<int>>& triangle){
        int row = triangle.size();
        int col = triangle[row-1].size();
        int dp[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) dp[i][j]=0;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(i==0&&j==0) dp[i][j] = triangle[0][0];
                else{
                    int up=1e9, diagonal=1e9;
                    if(i>0&&j<triangle[i-1].size()) up=triangle[i][j]+dp[i-1][j];
                    if(i>0&&j>0) diagonal=triangle[i][j]+dp[i-1][j-1];
                    dp[i][j]=min(up,diagonal);
                }
            }
        }
        int mini = 1e9;
        for(int j=0;j<triangle[row-1].size();j++) {
            mini = min(mini, dp[row-1][j]);
        }
        return mini;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<vector<int>> dp(row, vector<int>(col,-1));
        int mini = 1e9;
        for(int i=0;i<triangle[row-1].size();i++){
            // mini = min(mini, f(triangle,row-1,i,dp));
            mini = min(mini,f_tabulation(triangle));
        }
        return mini;
    }
};