class Solution{
public:
    long long minSumSquareDiff(vector<int>& nums1,vector<int>& nums2,int k1,int k2){
        long long k=(long long)k1+k2;
        vector<long long> freq(100001,0);
        long long ans=0;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            freq[d]++;
        }
        for(int d=100000;d>0&&k>0;d--){
            long long take=min(freq[d],k);
            long long full=take;
            long long next=d-1;
            long long count=freq[d];
            if(k>=count){
                freq[d-1]+=count;
                k-=count;
                freq[d]=0;
            }
            else{
                long long remain=k;
                long long lower=remain/count;
                long long rem=remain%count;
                freq[d]=0;
                freq[d-lower]+=count-rem;
                freq[d-lower-1]+=rem;
                k=0;
            }
        }
        for(int d=1;d<=100000;d++){
            ans+=(long long)d*d*freq[d];
        }
        return ans;
    }
};