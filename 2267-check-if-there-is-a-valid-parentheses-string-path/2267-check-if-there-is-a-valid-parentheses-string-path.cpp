class Solution {
private:
    bool f(vector<vector<char>>& grid, int row, int col, int bal,vector<vector<int>>& dp){
        if(grid[row][col]=='(') bal--;
        else bal++;
        if(bal<0) return false;
        if(row==0&&col==0) return bal==0;
        if(dp[row][col]!=-1) return dp[row][col];
        bool up = false, left = false;
        if(row>0) up = f(grid,row-1,col,bal,dp);
        if(col>0) left = f(grid,row,col-1,bal,dp);
        return dp[row][col]=up||left;
    }
    bool f_tabulation(vector<vector<char>>& grid){
        int n = grid.size(), m=grid[0].size();
        vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(m,vector<bool>(n+m+1)));
        if(grid[0][0]==')' || grid[n-1][m-1]=='(') return false;
        if(grid[0][0]=='(') dp[0][0][1]=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int bal=0;bal<n+m+1;bal++){
                    if(!dp[i][j][bal]) continue;
                    if(i+1<n){
                        int nb=bal+(grid[i+1][j]=='(' ? 1 : -1);
                        if(nb>=0) dp[i+1][j][nb]=true;
                    }
                    if(j+1<m){
                        int nb=bal+(grid[i][j+1]=='(' ? 1 : -1);
                        if(nb>=0) dp[i][j+1][nb]=true;
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // return f(grid,n-1,m-1,0,dp);
        return f_tabulation(grid);
    }
};