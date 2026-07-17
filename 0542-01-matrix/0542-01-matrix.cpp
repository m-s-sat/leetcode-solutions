class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int distance = q.front().first;
            q.pop();
            for(int i=0;i<4;i++){
                int nRow = row+drow[i];
                int nCol = col+dcol[i];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && !vis[nRow][nCol] && mat[nRow][nCol]==1){
                    vis[nRow][nCol] = 1;
                    q.push({distance+1,{nRow,nCol}});
                    ans[nRow][nCol] = distance+1;
                }
            }
        }
        return ans;
    }
};