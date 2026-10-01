class Solution {
private:
    bool f(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if(i<=0 && j<=0) return true;
        if(i>0 && j<=0) return false;
        if(i<=0 && j>0){
            for(int k=0;k<j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=f(s,p,i-1,j-1,dp);
        if(p[j-1]=='*') return dp[i][j]=f(s,p,i-1,j,dp) || f(s,p,i,j-1,dp);
        return dp[i][j]=false;
    }
    bool f_tabulation(string& s, string& p, int n, int m){
        vector<int> prev(m+1,0), cur(m+1,0);
        prev[0]=1;
        for(int j=1;j<=m;j++){
            if(p[j-1]=='*') prev[j] = prev[j-1];
        }
        for(int i=1;i<=n;i++){
            cur[0]=0;
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') cur[j]=prev[j-1];
                else if(p[j-1]=='*') cur[j]=prev[j]||cur[j-1];
                else cur[j]=0;
            }
            prev = cur;
        }
        return prev[m];
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f_tabulation(s,p,n,m);
    }
};