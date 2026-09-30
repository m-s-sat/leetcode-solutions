class Solution {
private:
    int f(string& s1, string& s2, int ind1, int ind2,vector<vector<int>>& dp){
        if(ind1<=0||ind2<=0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2]=1+f(s1,s2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=max(f(s1,s2,ind1-1,ind2,dp),f(s1,s2,ind1,ind2-1,dp));
    }
    int f_tabulation(string& s1, string& s2){
        int n = s1.size();
        int prev[n+1],cur[n+1];
        for(int i=0;i<=n;i++){
            prev[i]=0;
            cur[i]=0;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s1[ind1-1]==s2[ind2-1]) cur[ind2]=1+prev[ind2-1];
                else cur[ind2]=max(prev[ind2],cur[ind2-1]);
            }
            for(int i=0;i<=n;i++) prev[i]=cur[i];
        }
        return prev[n];
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s, s2 = "";
        s2.resize(n);
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++) s2[n-i-1] = s1[i];
        // return f(s1,s2,n,n,dp);
        return f_tabulation(s1,s2);
    }
};