class Solution {
private:
    int f(vector<int>& prices, int k, int buy, int ind, int n,vector<vector<vector<int>>>& dp){
        if(k==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][k][buy]!=-1) return dp[ind][k][buy];
        if(buy) return dp[ind][k][buy]=max(-prices[ind]+f(prices,k,0,ind+1,n,dp),f(prices,k,1,ind+1,n,dp)); 
        return dp[ind][k][buy]=max(prices[ind]+f(prices,k-1,1,ind+1,n,dp),f(prices,k,0,ind+1,n,dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return f(prices,k,1,0,n,dp);
    }
};