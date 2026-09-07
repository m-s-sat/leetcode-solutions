class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUlParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUlParent(parent[node]);
    }
    bool unionBySize(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v) return true;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        } 
        else{
            parent[ulp_u]=parent[ulp_v];
            size[ulp_v]+=size[ulp_u];
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DisjointSet ds(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            if(ds.unionBySize(u,v)) ans = {u,v};
        }
        return ans;
    }
};