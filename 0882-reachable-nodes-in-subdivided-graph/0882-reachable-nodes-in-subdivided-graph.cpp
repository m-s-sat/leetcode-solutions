class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        if(edges.size()==0) return 1;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]+1});
            adj[it[1]].push_back({it[0], it[2]+1});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        vector<int> dist(n,1e9);
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int newWt = it.second + wt;
                int adjNode = it.first;
                if(newWt<dist[adjNode]){
                    dist[adjNode] = newWt;
                    pq.push({newWt, adjNode});
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dist[i]<=maxMoves){
                ans ++;
            }
        }
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int cnt = it[2];
            int fromU = 0;
            int fromV = 0;
            if(dist[u] <= maxMoves) fromU = maxMoves - dist[u];
            if(dist[v] <= maxMoves) fromV = maxMoves - dist[v];
            ans += min(cnt, fromU + fromV);
        }
        return ans;
    }
};