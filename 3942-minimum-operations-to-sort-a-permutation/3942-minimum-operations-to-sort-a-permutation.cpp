class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int inc=0,dec=0;
        for(int i=0;i<n;i++){
            int next=nums[(i+1)%n];
            if(next!=(nums[i]+1)%n) inc++;
            if(next!=(nums[i]-1+n)%n) dec++;
        }
        if(inc==0) {
            int zero=find(nums.begin(), nums.end(), 0) - nums.begin();
            if (zero==0) return 0;
            return min(zero,n-zero+2);
        }
        if(dec==0){
            int largest=find(nums.begin(),nums.end(),n-1)-nums.begin();
            int k=(n-largest)%n;
            return 1+min(k,n-k);
        }
        return -1;
    }
};