class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++){
            profit = max(prices[i]-mini,profit);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};