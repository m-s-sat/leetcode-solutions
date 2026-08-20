class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            int last_arr1 = arr1.back();
            int last_arr2 = arr2.back();
            if(last_arr1>last_arr2) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        vector<int> result;
        for(auto it: arr1) result.push_back(it);
        for(auto it: arr2) result.push_back(it);
        return result;
    }
};