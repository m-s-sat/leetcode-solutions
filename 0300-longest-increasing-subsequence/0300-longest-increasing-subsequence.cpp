class Solution {
private:
    int f(vector<int>& nums, int ind, int prev,vector<vector<int>>& dp){
        if(ind==0) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int not_take = f(nums,ind-1,prev,dp);
        int take = 0;
        if(prev==0||nums[ind-1]<nums[prev-1]) take = 1+f(nums,ind-1,ind,dp);
        return dp[ind][prev]=max(take,not_take);
    }
    int f_tabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=1;ind<=n;ind++){
            for(int prev=n;prev>=0;prev--){
                int not_take = dp[ind-1][prev];
                int take = 0;
                if(prev==0||nums[ind-1]<nums[prev-1]) take=1+dp[ind-1][ind];
                dp[ind][prev]=max(take,not_take);
            }
        }
        return dp[n][0];

    }
    int space_optimisation(vector<int>& nums){
        int n = nums.size();
        vector<int> pre(n+1,0), cur(n+1,0);
        for(int ind=1;ind<=n;ind++){
            for(int prev=n;prev>=0;prev--){
                int not_take = pre[prev];
                int take = 0;
                if(prev==0||nums[ind-1]<nums[prev-1]) take=1+pre[ind];
                cur[prev]=max(take,not_take);
            }
            pre=cur;
        }
        return cur[0];
    }
    int further_space_optimisation(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) dp[i]=max(dp[i],1+dp[j]);
            }
            maxi = max(dp[i],maxi);
        }
        return maxi;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // return f(nums,n,0,dp);
        // return f_tabulation(nums);
        // return space_optimisation(nums);
        return further_space_optimisation(nums);
    }
};