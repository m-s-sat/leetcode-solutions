class DisjointSet{
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int k = n*n;
        DisjointSet ds(k);
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        vector<vector<int>> vis(n, vector<int>(n,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1 && !vis[row][col]){
                    int num1 = n*row+col;
                    vis[row][col] = 1;
                    for(int i=0;i<4;i++){
                        int nrow = row+drow[i];
                        int ncol = col+dcol[i];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                            int num2 = n*nrow+ncol;
                            ds.unionBySize(num1, num2);
                        }
                    }
                }
            }
        }
        int cnt = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0){
                    int total = 1;
                    set<int> components;
                    for(int i = 0; i < 4; i++){
                        int nrow = row + drow[i];
                        int ncol = col + dcol[i];

                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 1){
                            int num2 = n * nrow + ncol;
                            components.insert(ds.findUlParent(num2));
                        }
                    }
                    for(auto parent : components){
                        total += ds.size[parent];
                    }
                    cnt = max(cnt, total);
                }
            }
        }
        if(cnt==0) return n*n;
        return cnt;
    }
};