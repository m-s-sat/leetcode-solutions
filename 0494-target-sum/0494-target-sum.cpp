class Solution {
    int f(vector<int>& nums, int target, int ind, vector<vector<int>>& dp){
        if(ind==0){
            if(target==0 && nums[ind]==0) return 2;
            if(target==0 || nums[ind]==target) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_take = f(nums,target,ind-1,dp);
        int take = 0;
        if(target>=nums[ind]) take = f(nums,target-nums[ind],ind-1,dp);
        return dp[ind][target]= take+not_take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if((sum-target)%2!=0) return 0;
        if(sum-target<0) return 0;
        int targetSum = (sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(targetSum+1,-1));
        return f(nums,targetSum,n-1,dp);
    }
};