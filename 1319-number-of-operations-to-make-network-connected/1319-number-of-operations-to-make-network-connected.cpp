class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 0;
        }
    }
    int findUlParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUlParent(parent[node]);
    }
    int unionBySize(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v) return 1;
        if(ulp_u > ulp_v){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        return 0;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            extraEdges += ds.unionBySize(u,v);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        return cnt-1>extraEdges?-1:cnt-1;
    }
};