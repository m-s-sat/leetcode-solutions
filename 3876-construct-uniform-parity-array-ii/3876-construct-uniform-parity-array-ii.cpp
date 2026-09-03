class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mini = *(min_element(nums1.begin(), nums1.end()));
        bool ans = true;
        for(int i=0;i<n;i++){
            if(nums1[i]==mini) continue;
            if((nums1[i]-mini)%2!=(mini%2) && nums1[i]%2!=mini%2){
                ans = false;
                break;
            }
        }
        return ans;
    }
};