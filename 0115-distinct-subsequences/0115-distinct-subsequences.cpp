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
    long long f_tabulation(string &s, string &t){
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                long long not_take = dp[i+1][j];
                long long take = 0;
                if(s[i]==t[j]) take = dp[i+1][j+1];
                dp[i][j]=take+not_take;
            }
        }
        return dp[0][0];
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(s,t,0,0,dp);
        // return f_tabulation(s,t);
    }
};