class Solution {
private:
    pair<long long, vector<int>> f(vector<vector<int>>& intervals, vector<vector<long long>>& dpScore, vector<vector<vector<int>>>& dpPath, int ind, int count) {
        if (ind >= intervals.size() || count == 4) return {0, {}};
        if (dpScore[ind][count] != -1) return {dpScore[ind][count], dpPath[ind][count]};
        auto not_pick = f(intervals, dpScore, dpPath, ind + 1, count);
        int lo = ind + 1, hi = intervals.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid][0] > intervals[ind][1]) hi = mid;
            else lo = mid + 1;
        }
        auto pick = f(intervals, dpScore, dpPath, lo, count + 1);
        pick.first += intervals[ind][2];
        pick.second.push_back(intervals[ind][3]);
        sort(pick.second.begin(), pick.second.end());
        if (pick.first > not_pick.first || (pick.first == not_pick.first && pick.second < not_pick.second)) {
            dpScore[ind][count] = pick.first;
            dpPath[ind][count] = pick.second;
            return pick;
        }
        dpScore[ind][count] = not_pick.first;
        dpPath[ind][count] = not_pick.second;

        return not_pick;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<vector<long long>> dpScore(n, vector<long long>(5, -1));
        vector<vector<vector<int>>> dpPath(n, vector<vector<int>>(5));
        auto ans = f(intervals, dpScore, dpPath, 0, 0);
        return ans.second;
    }
};