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
    int f_tabulation(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit = 0;
                    if(buy) profit = max(-prices[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]);
                    else profit = max(prices[ind]+dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                    dp[ind][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int space_optimisation(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> cur(2,vector<int>(3,0));
        vector<vector<int>> ahead(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit = 0;
                    if(buy) cur[buy][cap] = max(-prices[ind]+ahead[0][cap], ahead[1][cap]);
                    else cur[buy][cap] = max(prices[ind]+ahead[1][cap-1], ahead[0][cap]);
                }
            }
            ahead = cur;
        }
        return cur[1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return f(prices,1,0,n,2,dp);
        // return f_tabulation(prices);
        return space_optimisation(prices);
    }
};