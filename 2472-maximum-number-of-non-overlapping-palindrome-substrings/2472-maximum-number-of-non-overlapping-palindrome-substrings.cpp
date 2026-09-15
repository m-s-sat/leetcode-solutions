class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n-1; i>=0; i--) {
            for(int j=i;j<n;j++) {
                if(s[i] == s[j] && (j-i<2 || dp[i+1][j-1])) dp[i][j] = true;
            }
        }
        int ans = 0, l = 0;
        for(int r=0;r<n;r++){
            for(int start = l; start<=r-k+1; start++) {
                if(dp[start][r]) {
                    ans++;
                    l=r+1;
                    break;
                }
            }
        }
        return ans;
    }
};