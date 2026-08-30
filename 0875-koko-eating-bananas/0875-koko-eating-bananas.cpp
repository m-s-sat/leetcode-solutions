class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<high){
            int mid = low+(high-low)/2;
            long long hours = 0;
            for(auto it: piles){
                hours+=it/mid;
                if(it%mid!=0) hours++;
            }
            if(hours<=h) high = mid; 
            else low=mid+1;
        }
        return low;
    }
};