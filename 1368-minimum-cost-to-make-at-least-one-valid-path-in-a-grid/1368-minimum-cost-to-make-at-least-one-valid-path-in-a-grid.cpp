class Solution {
private:
    
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(m,1e9));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        cost[0][0] = 0;
        pq.push({0,{0,0}});
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!pq.empty()){
            int curr_cost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return cost[row][col];
            if(grid[row][col]==1 && col+1 < m){
                if(cost[row][col]!=cost[row][col+1]){
                    cost[row][col+1] = curr_cost;
                    pq.push({curr_cost, {row, col+1}});
                }
            }
            if(grid[row][col]==2 && col-1>=0){
                if(cost[row][col]!=cost[row][col-1]){
                    cost[row][col-1] = curr_cost;
                    pq.push({curr_cost, {row, col-1}});
                }
            }
            if(grid[row][col]==3 && row+1<n){
                if(cost[row][col]!=cost[row+1][col]){
                    cost[row+1][col] = curr_cost;
                    pq.push({curr_cost, {row+1, col}});
                }
            }
            if(grid[row][col]==4 && row-1>=0){
                if(cost[row][col]!=cost[row-1][col]){
                    cost[row-1][col] = curr_cost;
                    pq.push({curr_cost, {row-1, col}});
                }
            }

            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int newCost = curr_cost + 1;
                    if(newCost<cost[nrow][ncol]){
                        cost[nrow][ncol] = newCost;
                        pq.push({newCost,{nrow,ncol}});
                    }
                }
            }
        }
        return cost[n-1][m-1];
    }
};