class Solution {
private:
    int f(string& s1, string& s2, int ind1, int ind2,vector<vector<int>>& dp){
        if(ind1<0||ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=1+f(s1,s2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=max(f(s1,s2,ind1-1,ind2,dp),f(s1,s2,ind1,ind2-1,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s, s2 = "";
        s2.resize(n);
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) s2[n-i-1] = s1[i];
        return f(s1,s2,n-1,n-1,dp);
    }
};