class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        pair<int,int> src = {0,0};
        pair<int, int> end = {n-1,n-1};
        set<pair<int, pair<int,int>>> st;
        st.insert({1,src});
        int drow[8] = {-1,-1,-1,0,0,1,1,1};
        int dcol[8] = {-1,0,1,-1,1,-1,0,1};
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) dist[i][j]=-1;
            }
        }
        while(!st.empty()){
            auto [distance, node] = *(st.begin());
            st.erase({distance, node});
            auto [row, col] = node;
            for(int i=0;i<8;i++){
                int nRow = row+drow[i];
                int nCol = col+dcol[i];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<n && grid[nRow][nCol]==0){
                    int newDistance = distance+1;
                    if(dist[nRow][nCol]!=1e9 && newDistance<dist[nRow][nCol]){
                        st.erase({dist[row][col], {row,col}});
                    }
                    if(newDistance<dist[nRow][nCol]){
                        dist[nRow][nCol] = newDistance;
                        st.insert({newDistance,{nRow,nCol}});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1];
    }
};