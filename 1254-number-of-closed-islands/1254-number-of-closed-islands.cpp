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
    void unionBySize(int u, int v){
        int ulp_u=findUlParent(u);
        int ulp_v=findUlParent(v);
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
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int unionSize = n*m;
        DisjointSet ds(unionSize);
        vector<int> boundary(unionSize,0);
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) continue;
                int node=i*m+j;
                if(i==0||j==0||i==n-1||j==m-1) boundary[node]=1;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj]==0){
                        int adjNode=ni*m+nj;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        vector<int> isBoundary(unionSize,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int root=ds.findUlParent(i*m+j);
                    if(boundary[i*m+j])
                        isBoundary[root]=1;
                }
            }
        }
        int ans=0;
        unordered_set<int> components;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int root=ds.findUlParent(i*m+j);
                    if(!isBoundary[root]&&components.insert(root).second)  ans++;
                }
            }
        }

        return ans;
    }
};