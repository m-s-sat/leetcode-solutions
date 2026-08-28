class Solution {
private:
    int f(vector<vector<int>>& matrix, int row, int col, int n,vector<vector<int>>& dp){
        if(row==0) return matrix[row][col];
        int rightDiagonal=INT_MAX, leftDiagonal=INT_MAX;
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        int up=matrix[row][col]+f(matrix,row-1,col,n,dp);
        if(col>0) leftDiagonal = matrix[row][col]+f(matrix,row-1,col-1,n,dp);
        if(col<n-1) rightDiagonal = matrix[row][col]+f(matrix,row-1,col+1,n,dp);
        return dp[row][col]=min(up,min(rightDiagonal,leftDiagonal));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int col=0;col<n;col++){
            mini = min(mini,f(matrix,n-1,col,n,dp));
        }
        return mini;
    }
};