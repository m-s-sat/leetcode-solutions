class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> cnt;
        for(int x:nums) cnt[x]++;
        if(k==n) return *max_element(nums.begin(), nums.end());
        int ans = -1;
        if(k==1) {           
            for(auto &p : cnt){
                if(p.second==1) ans = max(ans, p.first);
            }
            return ans;
        }
        if(cnt[nums[0]]==1) ans = max(ans, nums[0]);
        if(cnt[nums[n-1]]==1) ans = max(ans, nums[n-1]);
        return ans;
    }
};