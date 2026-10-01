class Solution {
private:
    int f(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        if(i<=0) return j;
        if(j<=0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]) return dp[i][j]=f(word1,word2,i-1,j-1,dp);
        return dp[i][j]=min(1+f(word1,word2,i-1,j,dp),min(1+f(word1,word2,i,j-1,dp),1+f(word1,word2,i-1,j-1,dp)));
    }
    int f_tabulation(string& word1, string& word2){
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++) dp[0][i]=i;
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(1+dp[i-1][j],min(1+dp[i-1][j-1],1+dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        // int n = word1.size(), m = word2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return f(word1,word2,n,m,dp);
        return f_tabulation(word1,word2);
    }
};