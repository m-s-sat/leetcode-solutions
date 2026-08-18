class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return -1;
        int left = 0, right = k-1;
        unordered_map<int,int> mp;
        while(right<n){
            set<int> st;
            for(int i=left;i<=right;i++){
                if(st.contains(nums[i])) continue;
                st.insert(nums[i]);
                mp[nums[i]]++;
            }
            left++, right++;
        }
        int ans = -1;
        for(auto it: mp){
            if(it.second==1) ans = max(ans,it.first);
        }
        return ans;
    }
};