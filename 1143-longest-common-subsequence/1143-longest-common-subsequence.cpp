class Solution {
private:
    int f(string& text1, string& text2, int ind1, int ind2,vector<vector<int>>& dp){
        if(ind1<0||ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]) return dp[ind1][ind2]=1+f(text1,text2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]= max(f(text1,text2,ind1-1,ind2,dp),f(text1,text2,ind1,ind2-1,dp));
    }
    int f_tabulation(string& text1, string& text2){
        int n = text1.length(), m = text2.length();
        // int dp[n+1][m+1];
        int prev[m+1],cur[m+1];
        for(int i=0;i<=m;i++){
            prev[i]=0;
            cur[i]=0;
        }       
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]) cur[ind2] = 1+prev[ind2-1];
                else cur[ind2]=max(prev[ind2],cur[ind2-1]);
            }
            for(int j=0;j<=m;j++) prev[j]=cur[j];
        }
        return prev[m];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.length(), m = text2.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(text1,text2,n-1,m-1,dp);
        return f_tabulation(text1,text2);
    }
};