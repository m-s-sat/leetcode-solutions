class Solution {
private:
    int f(string &s, string &target, int ind, int j,vector<vector<int>>& dp){
        if(j==target.size()) return 1;
        if(ind==s.size()) return 0;
        if(dp[ind][j]!=-1) return dp[ind][j];
        int take = 0;
        if(s[ind]==target[j]) take = f(s,target,ind+1,j+1,dp);
        int not_take = f(s,target,ind+1,j,dp);
        return dp[ind][j]=take+not_take;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(s,t,0,0,dp);
    }
};