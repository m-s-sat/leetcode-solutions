class Solution {
private:
    void f(vector<int>& nums, int ind, int end, int cnt, int sum,vector<vector<int>>& out) {
        if (ind == end) { out[cnt].push_back(sum); return; }
        f(nums, ind + 1, end, cnt, sum, out);
        f(nums, ind + 1, end, cnt + 1, sum + nums[ind], out);
    }
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(), n = N / 2;
        int total = 0;
        for (int x : nums) total += x;
        vector<vector<int>> left(n + 1), right(n + 1);
        f(nums, 0, n, 0, 0, left);
        f(nums, n, N, 0, 0, right);
        for (auto& v : right) sort(v.begin(), v.end());
        int mini = INT_MAX;
        for (int k = 0; k <= n; k++) {
            auto& v = right[n - k];
            for (int a : left[k]) {
                int want = total / 2 - a;
                int pos = lower_bound(v.begin(), v.end(), want) - v.begin();
                for (int j = max(0, pos - 1); j < min((int)v.size(), pos + 2); j++) {
                    int s1 = a + v[j];
                    mini = min(mini, abs(total - 2 * s1));
                }
            }
        }
        return mini;
    }
};