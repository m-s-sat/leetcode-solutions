class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUlParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUlParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_u]=parent[ulp_v];
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=parent[ulp_u];
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++) arr.push_back({nums[i],i});
        sort(arr.begin(), arr.end());
        int n = nums.size();
        DisjointSet ds(n);
        for(int i=1;i<n;i++){
            if(abs(arr[i].first-arr[i-1].first)<=limit){
                ds.unionBySize(arr[i].second,arr[i-1].second);
            }
        }
        unordered_map<int, vector<int>> groups;
        for (int i=0;i<n;i++) {
            groups[ds.findUlParent(i)].push_back(i);
        }
        for (auto& [root, indices] : groups) {
            vector<int> values;
            for (int idx : indices) {
                values.push_back(nums[idx]);
            }
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());
            for (int i=0;i<indices.size();i++) {
                nums[indices[i]] = values[i];
            }
        }
        return nums;
    }
};