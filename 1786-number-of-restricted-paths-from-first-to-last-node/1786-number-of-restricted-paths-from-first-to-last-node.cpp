class Solution {
private:
    vector<long long> distanceToLastNode(vector<vector<pair<int,int>>>& adj, int src, int n){
        vector<long long> dist(n+1,LLONG_MAX);
        priority_queue<
            pair<long long ,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long, long long>>
        > pq;
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            long long wt = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                long long adjNode = it.first;
                long long newWt = it.second + wt;
                if(newWt<dist[adjNode]){
                    dist[adjNode] = newWt;
                    pq.push({newWt, adjNode});
                }
            }
        }
        return dist;
    }
    int dfs(vector<vector<pair<int,int>>>& adj,int node,vector<long long>& dist,vector<int>& dp,int n){
        if (node == n) return 1;
        if (dp[node] != -1) return dp[node];

        long long ans = 0;

        for (auto &[adjNode, wt] : adj[node]) {
            if (dist[node] > dist[adjNode]) {
                ans += dfs(adj, adjNode, dist, dp, n);
                ans %= 1000000007;
            }
        }
        return dp[node] = ans;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long> dist = distanceToLastNode(adj, n, n);
        vector<int> dp(n + 1, -1);
        return dfs(adj, 1, dist, dp, n);
    }
};