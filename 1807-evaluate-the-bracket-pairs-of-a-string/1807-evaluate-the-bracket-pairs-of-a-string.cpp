class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] != '(') {
                ans += s[i];
            }
            else{
                int j = i + 1;
                string key;
                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }
                if(mp.find(key) != mp.end())  ans += mp[key];
                else  ans += '?';
                i = j;
            }
        }
        return ans;
    }
};