class Solution {
private:
    int f(vector<int>& coins, int amount, int ind,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(ind==0) return amount%coins[ind]==0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_take = f(coins,amount,ind-1,dp);
        int take = 0;
        if(amount>=coins[ind]) take = f(coins,amount-coins[ind],ind,dp);
        return dp[ind][amount]=take+not_take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(coins,amount,n-1,dp);
    }
};