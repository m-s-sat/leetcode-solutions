class Solution {
private:
    int f(string& s, string& t, int ind1, int ind2, vector<vector<int>>& dp){
        if(ind2<=0) return 1;
        if(ind1<=0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1-1]==t[ind2-1]) return dp[ind1][ind2]=f(s,t,ind1-1,ind2-1,dp)+f(s,t,ind1-1,ind2,dp);
        return dp[ind1][ind2]=f(s,t,ind1-1,ind2,dp);
    }
    int f_tabulation(string& s, string& t){
        int n = s.length(), m = t.length();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==t[ind2-1]){
                    dp[ind1][ind2]=(long long)dp[ind1-1][ind2-1]+dp[ind1-1][ind2];
                    dp[ind1][ind2]=min(dp[ind1][ind2],(long long)INT_MAX);
                }
                else dp[ind1][ind2]=dp[ind1-1][ind2];
            }
        }
        return dp[n][m];
    }
    int space_optimisation(string& s, string& t){
        int n = s.length(), m = t.length();
        vector<int> prev(m+1,0);
        prev[0]=1;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=m;ind2>0;ind2--){
                if(s[ind1-1]==t[ind2-1]){
                    long long ways=(long long)prev[ind2] + prev[ind2 - 1];
                    prev[ind2] = min(ways, (long long)INT_MAX);
                }
            }
        }
        return prev[m];
    }
public:
    int numDistinct(string s, string t) {
        // int n = s.length(), m = t.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return f(s,t,n,m,dp);
        // return f_tabulation(s,t);
        return space_optimisation(s,t);
    }
};