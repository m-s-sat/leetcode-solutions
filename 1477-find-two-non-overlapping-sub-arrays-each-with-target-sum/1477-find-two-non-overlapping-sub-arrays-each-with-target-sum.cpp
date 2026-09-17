class Solution {
public:
    int findStart(vector<int>& arr, int ind, int target) {
        int sum = 0;
        for(int j = ind; j >= 0; j--) {
            sum += arr[j];
            if(sum == target) return j;
            if(sum > target)  break;
        }
        return -1;
    }
    int solve(vector<int>& arr, int target, int ind, int cnt, vector<vector<int>>& dp) {
        if(cnt == 0)  return 0;
        if(ind < 0) return 1e9;
        if(dp[ind][cnt]!=-1) return dp[ind][cnt];
        int notPick = solve(arr, target, ind - 1, cnt,dp);
        int pick = 1e9;
        int start = findStart(arr, ind, target);
        if(start != -1){
            int len = ind - start + 1;
            pick = len + solve(arr, target, start - 1, cnt - 1,dp);
        }
        return dp[ind][cnt]=min(pick, notPick);
    }
    int solve_tabulation(vector<int>& arr, int target){
        int n = arr.size();
        int start[n],dp[n][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                dp[i][j]=1e9;
                start[i]=-1;
            }
        }
        int left = 0;
        long long sum = 0;
        for(int right = 0; right < n; right++) {
            sum += arr[right];
            while(sum > target) {
                sum -= arr[left];
                left++;
            }
            if(sum == target) {
                start[right] = left;
            }
        }
        for(int ind = 0; ind < n; ind++) {
            dp[ind][0] = 0;
        }
        for(int ind = 0; ind < n; ind++) {
            for(int cnt = 1; cnt <= 2; cnt++) {
                int notPick = (ind == 0) ? 1e9: dp[ind - 1][cnt];
                int pick = 1e9;
                if(start[ind] != -1) {
                    int len = ind - start[ind] + 1;
                    int previous;
                    if(start[ind] == 0) previous = (cnt == 1 ? 0 : 1e9);
                    else previous = dp[start[ind] - 1][cnt - 1];
                    pick = len + previous;
                }
                dp[ind][cnt] = min(pick, notPick);
            }
        }
        return dp[n-1][2];
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans = solve_tabulation(arr, target);
        return ans >= 1e9 ? -1 : ans;
    }
};