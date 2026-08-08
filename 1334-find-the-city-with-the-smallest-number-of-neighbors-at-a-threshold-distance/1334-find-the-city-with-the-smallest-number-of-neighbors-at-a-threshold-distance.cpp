class Solution {
private:
    int dijkstra(vector<vector<pair<int,int>>> &adj, int src, int n, int distanceThreshold){
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            for(auto &it: adj[node]){
                auto [adjEdge, edgeWt] = it;
                int newWt = edgeWt+wt;
                if(newWt<dist[adjEdge]){
                    dist[adjEdge] = newWt;
                    pq.push({newWt,adjEdge});
                }
            }
        }
        int city = 0;
        for(int i=0;i<n;i++){
            if(dist[i]<=distanceThreshold && dist[i]!=0 && i!=src){
                city++;
            }
        }
        return city;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int from  = edges[i][0];
            int to = edges[i][1];
            int wt = edges[i][2];
            adj[from].push_back({to,wt});
            adj[to].push_back({from,wt});
        }

        int cnt = n+1;
        int ans = -1;
        for(int i=0;i<n;i++){
            int citySize = dijkstra(adj,i,n,distanceThreshold);
            if (citySize <= cnt) {
                cnt = citySize;
                ans = i;
            }
        }
        return ans;

    }
};