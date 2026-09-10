class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            if(mp[nums[i]]>=1){
                return (i+3)/3;
            }
            mp[nums[i]]++;
        }
        return 0;
    }
};