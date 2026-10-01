class Solution {
private:
    int f(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        if(i<=0) return j;
        if(j<=0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]) return dp[i][j]=f(word1,word2,i-1,j-1,dp);
        return dp[i][j]=min(1+f(word1,word2,i-1,j,dp),min(1+f(word1,word2,i,j-1,dp),1+f(word1,word2,i-1,j-1,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(word1,word2,n,m,dp);
    }
};