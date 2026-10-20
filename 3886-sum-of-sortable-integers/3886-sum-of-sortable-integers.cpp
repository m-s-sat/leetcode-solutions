class Solution {
private:
    bool check(vector<int>& nums,vector<int>& sorted,int i,int k) {
        vector<int> p(k),lps(k,0);
        for(int j=0;j<k;j++) p[j]=sorted[i+j];
        for(int j=1,len=0;j<k;) {
            if(p[j]==p[len]) lps[j++]=++len;
            else if(len) len=lps[len-1];
            else lps[j++]=0;
        }
        int j=0;
        for(int t=0;t<2*k-1;t++) {
            int x=nums[i+t%k];
            while(j>0&&x!=p[j]) j=lps[j-1];
            if(x==p[j]) j++;
            if(j==k) return true;
        }
        return false;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        int ans=0;
        for(int k=1;k<=n;k++) {
            if(n%k!=0) continue;
            bool valid=true;
            for(int i=0;i<n;i+=k) {
                if(!check(nums,sorted,i,k)) {
                    valid=false;
                    break;
                }
            }
            if(valid) ans+=k;
        }
        return ans;
    }
};