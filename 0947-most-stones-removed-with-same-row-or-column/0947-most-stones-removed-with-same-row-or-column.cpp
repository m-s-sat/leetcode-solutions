class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUlParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUlParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol, it[1]);
        }
    
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> mp;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow +1;
            ds.unionBySize(nodeRow, nodeCol);
            mp[nodeRow] = 1;
            mp[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it: mp){
            if(ds.findUlParent(it.first)==it.first) cnt++;
        }
        return n-cnt;
    }
};