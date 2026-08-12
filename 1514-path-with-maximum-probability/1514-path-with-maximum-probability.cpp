class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double pb = succProb[i];
            adj[u].push_back({v,pb});
            adj[v].push_back({u,pb});
        }
        priority_queue<
            pair<double,int>,
            vector<pair<double,int>>,
            less<pair<double, int>>
        > pq;
        vector<double> probability(n,-1e9);
        probability[start_node] = 1.0;
        pq.push({1,start_node});
        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                double newProb = prob*it.second;
                if(newProb>probability[adjNode]){
                    probability[adjNode] = newProb;
                    pq.push({newProb, adjNode});
                }
            }
        }
        return probability[end_node] == -1e9? 0:probability[end_node];
    }
};