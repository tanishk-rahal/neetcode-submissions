class Solution {
public:
    int change(int amount, vector<int>& coins) {

        // dp[i] = number of combinations to make amount i
        vector<int> dp(amount + 1, 0);

        // One way to make amount 0: choose nothing
        dp[0] = 1;

        // Pick one coin at a time to avoid duplicate combinations
        for (int coin : coins) {

            // Try making every amount using the current coin
            for (int i = coin; i <= amount; i++) {

                // Add ways to make the remaining amount
                dp[i] += dp[i - coin];
            }
        }

        // Number of combinations to make the target amount
        return dp[amount];
    }
};