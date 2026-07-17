class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1)&&board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nRow = row+drow[i];
                int nCol = col+dcol[i];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && board[nRow][nCol]=='O' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0) board[i][j] = 'X';
            }
        }
    }
};