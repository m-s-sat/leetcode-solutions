class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            // 1-->0 graph structure
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];
            adj[second].push_back(first);
        }
        int n = adj.size();
        queue<int> q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};