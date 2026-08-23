class Solution {
private:
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
        vector<int> dp(n-1,-1);
        int num1 = f(nums, n-2,dp);
        vector<int> arr;
        for(int i=1;i<n;i++){
            arr.push_back(nums[i]);
            dp[i-1] = -1;
        }
        int num2 = f(arr, n-2, dp);
        return max(num1, num2);
    }
};