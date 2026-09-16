class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<long long> f(k+1,0), suf(k+1,0);
        for (int i=n-1; i>=0;i--) {
            for (int j =k; j>=1; j--) {
                f[j] = (f[j]+suf[j-1]) % MOD; 
                suf[j] = (suf[j]+f[j]) % MOD;
            }
            f[0] = 1;
            suf[0] = (suf[0] + 1) % MOD;
        }
        return f[k];
    }
};