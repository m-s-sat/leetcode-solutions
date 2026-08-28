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
    int f_tabulation(vector<vector<int>>& matrix){
        int n=matrix.size();
        int dp[n][n];
        for(int col=0;col<n;col++) dp[0][col]=matrix[0][col];
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(row==0) dp[row][col]=matrix[row][col];
                else{
                    int up=matrix[row][col]+dp[row-1][col];
                    int leftDiagonal = INT_MAX, rightDiagonal=INT_MAX;
                    if(col>0) leftDiagonal = matrix[row][col]+dp[row-1][col-1];
                    if(col<n-1) rightDiagonal = matrix[row][col]+dp[row-1][col+1];
                    dp[row][col]=min(up,min(rightDiagonal,leftDiagonal));
                }
            }
        }
        int mini = INT_MAX;
        for(int col=0;col<n;col++){
            mini = min(mini,dp[n-1][col]);
        }
        return mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n=matrix.size();
        // int mini = INT_MAX;
        // vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        // for(int col=0;col<n;col++){
        //     mini = min(mini,f(matrix,n-1,col,n,dp));
        // }
        return f_tabulation(matrix);
    }
};