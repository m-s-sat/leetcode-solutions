class Solution {
private:
    int f(vector<int>& prices, int ind, int maxPrice, vector<int>& dp){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int profit = maxPrice-prices[ind];
        return dp[ind]=max(profit,f(prices,ind-1,max(prices[ind], maxPrice),dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,-1);
        return f(prices,n-1,prices[n-1],dp);
    }
};