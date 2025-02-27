class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if (n == 0 || k == 0) return 0;

        // If k is greater than n/2, we can make any number of transactions (this turns into the "Best Time to Buy and Sell Stock II" problem)
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1]) {
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }

        // DP approach with a 2D table dp[k+1][n]
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        // Loop over the number of transactions
        for (int t = 1; t <= k; t++) {
            int maxDiff = -prices[0]; // maxDiff tracks the maximum value of dp[t-1][i] - prices[i]
            // Loop over each day
            for (int d = 1; d < n; d++) {
                dp[t][d] = max(dp[t][d-1], prices[d] + maxDiff); // Either do nothing or sell today after the best buy before today
                maxDiff = max(maxDiff, dp[t-1][d] - prices[d]); // Update maxDiff for the next day's decision
            }
        }

        return dp[k][n-1];
    }
};
