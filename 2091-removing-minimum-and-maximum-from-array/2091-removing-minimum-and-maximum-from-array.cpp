class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int min_idx=0,max_idx=0;
        for(int i=1;i<n;i++) {
            if(nums[i]<nums[min_idx]) min_idx = i;
            if(nums[i]>nums[max_idx]) max_idx = i;
        }
        int f_case = max(min_idx,max_idx)+1;
        int s_case = n-min(min_idx,max_idx);
        int t_case = min(min_idx,max_idx)+n-max(min_idx,max_idx)+1;
        return min(f_case,min(s_case,t_case));
    }
};