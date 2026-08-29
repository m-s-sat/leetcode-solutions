class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(prefix[i]==k) cnt++;
            int diff = prefix[i]-k;
            if(mp.find(diff)!=mp.end()) cnt+=mp[diff];
            mp[prefix[i]]++;
        }
        return cnt;
    }
};