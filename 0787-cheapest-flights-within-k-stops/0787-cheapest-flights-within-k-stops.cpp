class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            adj[from].push_back({to,price});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n, 1e9);
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edwt = it.second;
                if(cost+edwt<dist[adjNode] && stops<=k){
                    dist[adjNode] = cost+edwt;
                    q.push({stops+1,{adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};