class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;
        auto [min_val, min_idx] = *mp.begin();
        auto [max_val, max_idx] = *prev(mp.end());
        int f_case = max(min_idx,max_idx)+1;
        int s_case = n-min(min_idx,max_idx);
        int t_case = min(min_idx,max_idx)+n-max(min_idx,max_idx)+1;
        return min(f_case,min(s_case,t_case));
    }
};