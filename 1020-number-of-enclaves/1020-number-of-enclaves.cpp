class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rSize = grid.size();
        int cSize = grid[0].size();
        vector<vector<int>> vis(rSize, vector<int>(cSize,0));
        queue<pair<int,int>> q;
        for(int i=0;i<rSize;i++){
            for(int j=0;j<cSize;j++){
                if((j==0 || j==cSize-1 || i==0 || i==rSize-1) && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> dRow = {-1,0,1,0};
        vector<int> dCol = {0,1,0,-1};
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            for(int i=0;i<4;i++){
                int nRow = row+dRow[i];
                int nCol = col+dCol[i];
                if(nRow>=0 && nCol>=0 && nRow<rSize && nCol<cSize && !vis[nRow][nCol] && grid[nRow][nCol]==1){
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
        int ans = 0;
        for(int i=0;i<rSize;i++){
            for(int j=0;j<cSize;j++){
                if(grid[i][j]==1 && !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};