class Solution {
private:
    int f(vector<int>& nums, int target, int ind,vector<vector<int>>& dp){
        if(target<-1000 || target>1000) return 0;
        if(ind==0){
            if(target==0 && nums[ind]==0) return 2;
            if(target==nums[ind] || target==-nums[ind]) return 1;
            return 0;
        }
        if(dp[ind][target+1000]!=-1) return dp[ind][target+1000];
        int sub = f(nums,target-nums[ind],ind-1,dp);
        int plus = f(nums,target+nums[ind],ind-1,dp);
        return dp[ind][target+1000]= plus+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(20001,-1));
        return f(nums,target,n-1,dp);
    }
};