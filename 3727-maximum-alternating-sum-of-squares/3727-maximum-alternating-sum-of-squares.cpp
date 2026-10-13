class Solution{
public:
    long long maxAlternatingSum(vector<int>&nums){
        sort(nums.begin(),nums.end(),[](int a,int b){
            return 1LL*a*a>1LL*b*b;
        });
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long sq=1LL*nums[i]*nums[i];
            if(i<(n+1)/2) ans+=sq;
            else ans-=sq;
        }
        return ans;
    }
};