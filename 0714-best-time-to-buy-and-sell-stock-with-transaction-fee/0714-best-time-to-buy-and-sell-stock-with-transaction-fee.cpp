class Solution {
private:
    int f(vector<int>& prices, int fee, int n, int ind, int buy, vector<vector<int>>& dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy) return dp[ind][buy]=max(-prices[ind]-fee+f(prices,fee,n,ind+1,0,dp),f(prices,fee,n,ind+1,1,dp));
        return dp[ind][buy]=max(prices[ind]+f(prices,fee,n,ind+1,1,dp),f(prices,fee,n,ind+1,0,dp));
    }
    int f_tabulation(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy) dp[ind][buy]=max(-prices[ind]-fee+dp[ind+1][0],dp[ind+1][1]);
                else dp[ind][buy]=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
            }
        }
        return dp[0][1];
    }
    int space_optimisation(vector<int>& prices, int fee){
        int n = prices.size();
        vector<int> cur(2,0), ahead(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy) cur[buy]=max(-prices[ind]-fee+ahead[0],ahead[1]);
                else cur[buy]=max(prices[ind]+ahead[1],ahead[0]);
            }
            ahead=cur;
        }
        return cur[1];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return f(prices,fee,n,0,1,dp);
        // return f_tabulation(prices,fee);
        return space_optimisation(prices,fee);
    }
};