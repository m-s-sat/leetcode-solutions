class Solution {
private:
    int f(vector<int>& coins, int amount, int ind,vector<vector<int>>& dp){
        if(ind==0) return amount%coins[ind]==0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_take = f(coins,amount,ind-1,dp);
        int take = 0;
        if(amount>=coins[ind]) take = f(coins,amount-coins[ind],ind,dp);
        return dp[ind][amount]=take+not_take;
    }
    long long f_tabulation(vector<int>& coins, int amount){
        int n = coins.size();
        long long dp[n][amount+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++) dp[i][j]=0;
        }
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0) dp[0][j]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                long long not_take = dp[i-1][j];
                long long take = 0;
                if(j>=coins[i]) take = dp[i][j-coins[i]];
                dp[i][j]=take+not_take;
            }
        }
        return dp[n-1][amount];
    }
    long long space_optimisation(vector<int>& coins, int amount){
        int n = coins.size();
        vector<long long> prev(amount+1,0), curr(amount+1,0);
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0) prev[j]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                long long not_take = prev[j];
                long long take = 0;
                if(j>=coins[i]) take = curr[j-coins[i]];
                curr[j]=take+not_take;
            }
            prev=curr;
        }
        return prev[amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(coins,amount,n-1,dp);
        // return space_optimisation(coins,amount);
    }
};