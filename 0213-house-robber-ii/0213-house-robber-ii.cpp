class Solution {
private:
    int spaceOptimization(vector<int>& nums, int n){
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int not_take = prev1;
            int curr = max(take, not_take);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int tabulation(vector<int>& nums, int n){
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=dp[i-2];
            int not_take = dp[i-1];
            dp[i] = max(take, not_take);
        }
        return dp[n-1];
    }
    int f(vector<int>& nums, int ind,vector<int>& dp){
        if(ind==0) return nums[ind];
        if(ind<1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind] + f(nums,ind-2,dp);
        int non_pick = 0 + f(nums,ind-1,dp);
        return dp[ind] = max(pick, non_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int num1 = spaceOptimization(nums, n-1);
        vector<int> arr;
        for(int i=1;i<n;i++) arr.push_back(nums[i]);
        int num2 = spaceOptimization(arr, n-1);
        return max(num1, num2);
    }
};