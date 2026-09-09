class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int findUlParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUlParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v) return ;
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
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,string> mp;
        int n = strs.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            string s1 = strs[i];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                string s2 = strs[j];
                int count_mismatch = 0;
                int len = s2.size();
                for(int k=0;k<len;k++){
                    if(s1[k]!=s2[k]) count_mismatch++;
                }
                if(count_mismatch<=2 && count_mismatch%2==0) ds.unionBySize(i,j);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ds.findUlParent(i)==i) ans++;
        }
        return ans;
    }
};