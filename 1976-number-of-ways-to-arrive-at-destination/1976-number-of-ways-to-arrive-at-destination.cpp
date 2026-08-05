class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n,0);
        ways[0] = 1;
        dist[0] = 0;
        int MOD = 1000000007;
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if(time>dist[node]) continue;
            for(auto &it: adj[node]){
                long long newTime = time+it.second;
                int adjNode = it.first;
                if(dist[adjNode]>newTime){
                    pq.push({newTime, adjNode});
                    ways[adjNode] = ways[node];
                    dist[adjNode] = newTime;
                }
                else if (newTime == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};