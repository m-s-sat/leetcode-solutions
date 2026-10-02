class Solution {
private:
    int f(vector<int>& prices, int buy, int ind, int n, int cap,vector<vector<vector<int>>>& dp){
        if(cap==0) return 0;
        if(ind==n) return 0;
        int profit = 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy) profit = max(-prices[ind]+f(prices,0,ind+1,n,cap,dp),f(prices,1,ind+1,n,cap,dp));
        else profit = max(prices[ind]+f(prices,1,ind+1,n,cap-1,dp),f(prices,0,ind+1,n,cap,dp));
        return dp[ind][buy][cap]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,1,0,n,2,dp);
    }
};