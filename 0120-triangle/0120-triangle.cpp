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
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<vector<int>> dp(row, vector<int>(col,-1));
        int mini = 1e9;
        for(int i=0;i<triangle[row-1].size();i++){
            mini = min(mini, f(triangle,row-1,i,dp));
        }
        return mini;
    }
};