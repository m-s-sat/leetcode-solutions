class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            adj[u].push_back({v,t});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        vector<int> dist(n+1, 1e9);
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            auto [dt, node] = pq.top();
            pq.pop();
            if(dt>dist[node]) continue;
            for(auto it: adj[node]){
                int nt = dt+it.second;
                int adjNode = it.first;
                if(nt<dist[adjNode]){
                    pq.push({nt, adjNode});
                    dist[adjNode] = nt;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n; i++){
            if(dist[i]==1e9) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};