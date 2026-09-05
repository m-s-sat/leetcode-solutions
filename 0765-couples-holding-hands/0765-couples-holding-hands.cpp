class DisjointSet {
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUlParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUlParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=parent[ulp_u];
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=parent[ulp_v];
            size[ulp_v]+=size[ulp_u];
        }
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DisjointSet ds(n/2);
        for(int i=0;i<n;i+=2){
            int person1 = row[i];
            int person2 = row[i+1];
            int couple1 = person1/2;
            int couple2 = person2/2;
            ds.unionBySize(couple1,couple2);
        }
        int components = 0;
        for(int i=0;i<n/2;i++){
            if(i==ds.findUlParent(i)) components++;
        }
        return n/2-components;
    }
};