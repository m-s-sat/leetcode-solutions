class Solution {
private:
    int f(vector<vector<int>>& grid, int i,int j1,int j2,int n, int m, vector<vector<vector<int>>>& dp){
        if(j1<0||j2<0||j1>=m||j2>=m) return -1e8;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int dcol[3]={-1,0,1};
        int maxi=-1;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j1==j2) maxi=max(maxi,grid[i][j1]+f(grid,i+1,j1+dcol[j],j2+dcol[k],n,m,dp));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(grid,i+1,j1+dcol[j],j2+dcol[k],n,m,dp));
            }

        }
        return dp[i][j1][j2]=maxi;
    }
    int f_tabulation(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++) dp[i][j][k]=0;
            }
        }
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int dcol[3] = {-1,0,1};
                    int maxi = -1;
                    for(int k=0;k<3;k++){
                        for(int l=0;l<3;l++){
                            int nj1=j1+dcol[k],nj2=j2+dcol[l];
                            if(nj1<0||nj1>=m||nj2<0||nj2>=m) continue;
                            int value;
                            if(j1==j2) value = grid[i][j1];
                            else value=grid[i][j1]+grid[i][j2];
                            value+=dp[i+1][nj1][nj2];
                            maxi=max(maxi,value);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m, -1)));
        // return f(grid,0,0,m-1,n,m,dp);
        return f_tabulation(grid);
    }
};