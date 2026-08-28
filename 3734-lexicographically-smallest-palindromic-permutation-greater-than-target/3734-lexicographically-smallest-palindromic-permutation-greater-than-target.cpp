class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        int odd = 0;
        char mid = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }
        if(odd > 1 || (n % 2 == 0 && odd != 0)) {
            return "";
        }
        int m = n / 2;
        string half = "";
        for(int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, char('a' + i));
        }
        string targetHalf = target.substr(0, m);
        vector<int> cnt(26, 0);
        for (char c : half) cnt[c - 'a']++;
        bool equalPossible = true;
        for(char c : targetHalf) {
            if(cnt[c - 'a'] == 0) {
                equalPossible = false;
                break;
            }
            cnt[c - 'a']--;
        }
        if(equalPossible) {
            string ans = targetHalf;
            if(n%2) ans += mid;
            string rev = targetHalf;
            reverse(rev.begin(), rev.end());
            ans += rev;
            if(ans > target) return ans;
        }
        for(int pos = m - 1; pos >= 0; pos--) {
            vector<int> remaining(26, 0);
            for(char c : half) remaining[c - 'a']++;
            bool possible = true;
            for(int i = 0; i < pos; i++) {
                int c = targetHalf[i] - 'a';
                if (remaining[c] == 0) {
                    possible = false;
                    break;
                }
                remaining[c]--;
            }
            if(!possible) continue;
            int targetChar = targetHalf[pos] - 'a';
            for(int c = targetChar + 1; c < 26; c++) {
                if(remaining[c] == 0) continue;
                string newHalf = targetHalf.substr(0, pos);
                newHalf += char('a' + c);
                remaining[c]--;
                for(int x = 0; x < 26; x++) {
                    while(remaining[x] > 0) {
                        newHalf += char('a' + x);
                        remaining[x]--;
                    }
                }
                string ans = newHalf;
                if(n%2)  ans += mid;                
                string rev = newHalf;
                reverse(rev.begin(), rev.end());
                ans += rev;
                return ans;
            }
        }
        return "";
    }
};