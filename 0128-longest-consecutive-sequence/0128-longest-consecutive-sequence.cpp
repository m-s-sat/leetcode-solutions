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
        if(ulp_u==ulp_v) return ;
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
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return n;
        vector<pair<int,int>> nums2;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()) continue;
            nums2.push_back({nums[i], i});
            mp[nums[i]] = 1;
        }
        int m = nums2.size();
        DisjointSet ds(n);
        sort(nums2.begin(),nums2.end());
        for(int i=1;i<m;i++){
            if(nums2[i].first==nums2[i-1].first+1){
                ds.unionBySize(nums2[i].second, nums2[i-1].second);
            }
        }
        int max_size = *max_element(ds.size.begin(),ds.size.end());
        return max_size;
    }
};