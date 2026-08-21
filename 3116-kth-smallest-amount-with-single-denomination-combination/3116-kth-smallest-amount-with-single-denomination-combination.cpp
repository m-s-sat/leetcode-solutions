class Solution {
private:
    long long count;
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    void dfs(vector<int>& coins, int index, long long lcm, int selected, long long mid) {
        if (selected > 0) {
            if (selected % 2 == 1) count += mid / lcm;
            else count -= mid / lcm;
        }
        for (int i = index; i < coins.size(); i++) {
            long long newLcm = lcm / gcd(lcm, coins[i]) * coins[i];
            if (newLcm > mid) continue;
            dfs(coins, i + 1, newLcm, selected + 1, mid);
        }
    }

    bool check(vector<int>& coins, long long k, long long mid) {
        count = 0;
        dfs(coins, 0, 1, 0, mid);
        return count >= k;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long left = 1;
        long long right = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(coins, k, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};