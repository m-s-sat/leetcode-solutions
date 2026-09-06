class Solution {
private:
    int f(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp){
        if(ind==0){
            if(amount%coins[ind]==0) return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_take = f(coins,amount,ind-1,dp);
        int take = 1e9;
        if(coins[ind]<=amount) take = 1 + f(coins,amount-coins[ind],ind,dp);
        return dp[ind][amount]=min(take,not_take);
    }
    int f_tabulation(vector<int>& coins, int amount){
        int n = coins.size();
        int dp[n][amount+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++) dp[i][j]=0;
        }
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int not_take = dp[i-1][j];
                int take = 1e9;
                if(coins[i]<=j && j>=coins[i]) take = 1+dp[i][j-coins[i]];
                dp[i][j]=min(take,not_take);
            }
        }
        return dp[n-1][amount]>=1e9?-1:dp[n-1][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // int ans = f(coins,amount,n-1,dp);
        // if(ans>=1e9) return -1;
        // return ans;
        return f_tabulation(coins,amount);
    }
};