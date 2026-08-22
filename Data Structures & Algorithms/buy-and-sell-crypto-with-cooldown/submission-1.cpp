class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // dp[i][buy]:
        // i    = current day
        // buy  = 1 -> we are allowed to BUY
        // buy  = 0 -> we are holding a stock, so we can SELL
        //
        // n + 2 because while selling we use dp[i + 2]
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // We go from right to left because
        // dp[i] depends on future states: dp[i+1] and dp[i+2]
        for(int i = n - 1; i >= 0; i--) {

            // ---------------- BUY STATE ----------------
            // We are allowed to buy a stock.
            //
            // Choice 1: BUY today
            // Pay prices[i], so profit becomes -prices[i]
            // After buying, we are holding a stock -> state 0
            //
            // Choice 2: SKIP today
            // Remain in the BUY state and move to next day
            dp[i][1] = max(
                -prices[i] + dp[i + 1][0],  // BUY
                dp[i + 1][1]               // SKIP
            );


            // ---------------- SELL STATE ----------------
            // We are currently holding a stock.
            //
            // Choice 1: SELL today
            // Get prices[i] as profit.
            // After selling, there is a 1-day cooldown,
            // so we jump to i + 2.
            //
            // After selling, we can buy again -> state 1
            //
            // Choice 2: SKIP selling today
            // Continue holding the stock and move to next day
            dp[i][0] = max(
                prices[i] + dp[i + 2][1], // SELL + cooldown
                dp[i + 1][0]             // SKIP
            );
        }

        // At day 0, we don't own any stock,
        // so initially we are allowed to BUY.
        //
        // Therefore the answer is dp[0][1]
        return dp[0][1];
    }
};