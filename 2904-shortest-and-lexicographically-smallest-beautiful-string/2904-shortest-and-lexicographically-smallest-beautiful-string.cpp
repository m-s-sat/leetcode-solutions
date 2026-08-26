class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int right = 0, left = 0, cnt = 0;
        string ans = "";
        while(right<n){
            if(s[right]=='1') cnt++;
            while(left<n && cnt>k){
                if(s[left]=='1') cnt--;
                left++;
            }
            while (left<=right && s[left] == '0') left++;
            if(cnt==k){
                string curr = s.substr(left,right-left+1);
                if(ans=="" || curr.length()<ans.length() || (curr.length() == ans.length() && curr < ans)) ans = curr;
            }
            right++;
        }
        return ans;
    }
};