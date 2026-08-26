class Solution {
private:
    bool check(vector<vector<int>>& adj, vector<int>& vis, int node, int parent){
        vis[node] = !vis[parent];
        for(auto it: adj[node]){
            if(vis[it]==-1){
                if(check(adj, vis, it, node)==false) return false;
            }
            if(vis[node]==vis[it]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!check(graph, vis, i, i)) return false;
            }
        }
        return true;
    }
};