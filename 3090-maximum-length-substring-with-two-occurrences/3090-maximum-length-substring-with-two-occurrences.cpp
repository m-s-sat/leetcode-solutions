class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;
        int n = s.length();
        int freq[26] = {0};
        int ans = 0;
        while(right<n){
            int idx = s[right] - 'a';
            freq[idx]++;
            while(freq[idx]>2){
                int idx2 = s[left] - 'a';
                freq[idx2]--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};