class Solution {
public:
    pair<int,int> expand(string &s, int l, int r) {
    while (l>=0 && r<s.size() && s[l]==s[r]) l--, r++; 
    return {l+1, r-1};
    }

    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            auto [l1, r1] = expand(s, i, i);       
            auto [l2, r2] = expand(s, i, i + 1);   
            if (r1-l1+1 > maxLen) {
                start = l1; 
                maxLen = r1 - l1 + 1;
            }
            if (r2-l2+1 > maxLen) {
                start = l2;
                maxLen = r2 - l2 + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};