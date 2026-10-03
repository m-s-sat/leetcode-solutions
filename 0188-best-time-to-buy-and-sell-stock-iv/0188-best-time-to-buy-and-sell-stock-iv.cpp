class Solution {
private:
    int f(vector<int>& prices, int k, int buy, int ind, int n,vector<vector<vector<int>>>& dp){
        if(k==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][k][buy]!=-1) return dp[ind][k][buy];
        if(buy) return dp[ind][k][buy]=max(-prices[ind]+f(prices,k,0,ind+1,n,dp),f(prices,k,1,ind+1,n,dp)); 
        return dp[ind][k][buy]=max(prices[ind]+f(prices,k-1,1,ind+1,n,dp),f(prices,k,0,ind+1,n,dp));
    }
    int f_tabulation(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int j=1;j<=k;j++){
                for(int buy=0;buy<=1;buy++){
                    if(buy) dp[ind][j][buy]=max(-prices[ind]+dp[ind+1][j][0],dp[ind+1][j][1]);
                    else dp[ind][j][buy]=max(prices[ind]+dp[ind+1][j-1][1],dp[ind+1][j][0]);
                }
            }
        }
        return dp[0][k][1];
    }
    int space_optimisation(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<int>> cur(k+1,vector<int>(2,0)), ahead(k+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int j=1;j<=k;j++){
                for(int buy=0;buy<=1;buy++){
                    if(buy) cur[j][buy]=max(-prices[ind]+ahead[j][0],ahead[j][1]);
                    else cur[j][buy]=max(prices[ind]+ahead[j-1][1],ahead[j][0]);
                }
                ahead = cur;
            }
        }
        return cur[k][1];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        // return f(prices,k,1,0,n,dp);
        // return f_tabulation(prices,k);
        return space_optimisation(prices,k);
    }
};