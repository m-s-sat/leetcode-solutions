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
    int f_tabulation(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy) profit = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                else profit = max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int space_optimisation(vector<int>& prices){
        int n = prices.size();
        int prev[2], cur[2];
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy) profit = max(-prices[ind]+prev[0],prev[1]);
                else profit = max(prices[ind]+prev[1],prev[0]);
                cur[buy] = profit;
            }
            prev[0]=cur[0];
            prev[1]=cur[1];
        }
        return prev[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return space_optimisation(prices);
        // return f_tabulation(prices);
    }
};