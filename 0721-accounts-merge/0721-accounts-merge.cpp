class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findUlParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUlParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, pair<string,int>> mp;
        vector<pair<int,int>> edges;
        int n = accounts.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                string name = accounts[i][0];
                if(mp.find(email)!=mp.end()){
                    pair<int,int> edge = {i,mp[email].second};
                    edges.push_back(edge);
                }
                else mp[email] = {name, i};
            }
        }
        int m = edges.size();
        DisjointSet ds(n);
        for(int i=0;i<m;i++){
            auto [u,v] = edges[i];
            ds.unionBySize(u,v);
        }
        vector<vector<string>> ans(n);
        for(auto &it : mp){
            string email = it.first;
            int node = it.second.second;
            int root = ds.findUlParent(node);
            ans[root].push_back(email);
        }
        vector<vector<string>> result;
        for(int i = 0; i < n; i++){
            if(ans[i].empty()) continue;
            sort(ans[i].begin(), ans[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &email : ans[i]) temp.push_back(email);
            result.push_back(temp);
        }
        return result;
    }
};