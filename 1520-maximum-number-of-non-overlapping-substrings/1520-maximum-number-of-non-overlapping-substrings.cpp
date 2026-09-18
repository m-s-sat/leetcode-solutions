class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        vector<pair<int,int>> iv;  
        for (int c=0; c<26; c++) {
            if (first[c] == -1) continue;
            int l = first[c], r = last[c];
            bool ok = true;
            for(int i=l; i<=r; i++) {
                int d = s[i] - 'a';
                if (first[d]<l) { 
                    ok = false; 
                    break; 
                }
                r = max(r, last[d]);
            }
            if(ok) iv.push_back({r, l});
        }

        sort(iv.begin(), iv.end());
        vector<string> res;
        int prevEnd = -1;
        for (auto &[r, l] : iv) {
            if(l>prevEnd) {
                res.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }
        return res;
    }
};