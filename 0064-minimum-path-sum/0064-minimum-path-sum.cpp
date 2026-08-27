class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        while(!pq.empty()){
            int val = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            int nrow = row+1;
            int ncol = col+1;
            if(nrow<n){
                int newDist = val+grid[nrow][col];
                if(newDist<dist[nrow][col]){
                    pq.push({newDist,{nrow,col}});
                    dist[nrow][col] = newDist;
                }
            }
            if(ncol<m){
                int newDist = val+grid[row][ncol];
                if(newDist<dist[row][ncol]){
                    pq.push({newDist,{row,ncol}});
                    dist[row][ncol] = newDist;
                }
            }
        }
        return dist[n-1][m-1]==1e9?grid[0][0]:dist[n-1][m-1];
    }
};