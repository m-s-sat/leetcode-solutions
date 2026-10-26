class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 || vis[i][j]) continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                long long sum=0;
                sum+=grid[i][j];
                vis[i][j]=1;
                while(!q.empty()){
                    auto [row,col]=q.front();
                    q.pop();
                    for(int d=0;d<4;d++){
                        int nrow=row+drow[d];
                        int ncol=col+dcol[d];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]>0 && !vis[nrow][ncol]){
                            sum+=grid[nrow][ncol];
                            q.push({nrow,ncol});
                            vis[nrow][ncol]=1;
                        }
                    }
                }
                if(sum%k==0) ans++;
            }
        }
        return ans;

    }
};