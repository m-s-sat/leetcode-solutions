class Solution {
private:
    bool f(vector<int>& nums, int ind, int target, vector<vector<int>>& dp){
        if(target==nums[ind]) return true;
        if(ind==0) return nums[ind]==target;
        if(dp[ind][target]!=-1) return dp[ind][target]==1?true:false;
        bool not_take = f(nums,ind-1,target,dp);
        bool take = false;
        if(nums[ind]<=target) take = f(nums,ind-1,target-nums[ind],dp);
        return dp[ind][target] = take||not_take?1:0;
    }
public:
    bool canPartition(vector<int>& nums) {
        int target = 0, n=nums.size();
        for(int i=0;i<n;i++) target+=nums[i];
        if(target&1) return false;
        vector<vector<int>> dp(n,vector<int>(target/2+1,-1));
        return f(nums,n-1,target/2,dp);
    }
};