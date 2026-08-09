class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        priority_queue<
            pair<int, pair<pair<int,int>,int>>,
            vector<pair<int, pair<pair<int,int>,int>>>,
            greater<pair<int,pair<pair<int,int>,int>>>
        > pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        vector<vector<int>> minBricks(n, vector<int>(m, 1e9));
        int brick = grid[0][0]==0?0:1;
        minBricks[0][0] = brick;
        pq.push({0,{{0,0},brick}});
        dist[0][0] = 0;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int distance = it.first;
            int used_brick = it.second.second;
            int row = it.second.first.first;
            int col = it.second.first.second;
            if(used_brick>k) continue;
            if(row==n-1 && col==m-1) return distance;
            for(int i=0;i<4;i++){
                int nrow = drow[i]+row;
                int ncol = dcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int temp1 = used_brick + (grid[nrow][ncol]==1 ? 1 : 0);
                    if(temp1 < minBricks[nrow][ncol] && temp1 <= k){
                        minBricks[nrow][ncol] = temp1;
                        pq.push({distance+1,{{nrow,ncol},temp1}});
                    }
                }
            }
        }
        return -1;
    }
};