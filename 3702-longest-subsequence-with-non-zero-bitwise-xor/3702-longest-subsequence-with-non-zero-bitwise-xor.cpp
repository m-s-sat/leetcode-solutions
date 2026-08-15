class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool allZero = true;
        for(int i=0;i<n;i++) {
            xr^=nums[i];
            if (nums[i]!=0) allZero = false;
        }
        if(allZero) return 0;
        return xr==0?n-1:n;
    }
};