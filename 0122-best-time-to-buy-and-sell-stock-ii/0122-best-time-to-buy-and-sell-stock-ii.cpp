class Solution {
private:
    int f(vector<int>& prices, int canBuy, int ind, int n, vector<vector<int>>& dp){
        if(ind==n) return 0;
        int profit = 0;
        if(dp[ind][canBuy]!=-1) return dp[ind][canBuy];
        if(canBuy) profit = max(-prices[ind]+f(prices,0,ind+1,n,dp),f(prices,1,ind+1,n,dp));
        else profit = max(prices[ind]+f(prices,1,ind+1,n,dp),f(prices,0,ind+1,n,dp));
        return dp[ind][canBuy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,1,0,n,dp);
    }
};