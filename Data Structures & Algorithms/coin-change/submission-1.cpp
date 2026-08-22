class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, amount + 1);
        
        dp[0] = 0; // 0 coins needed to make amount 0

        for (int i = 1; i <= amount; i++) {
            
            // Try every coin for current amount
            for (int j = 0; j < coins.size(); j++) {
                
                // Coin can be used only if it <= current amount
                if (coins[j] <= i) {
                    
                    // Use current coin and solve remaining amount
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // If amount is still impossible, return -1
        return dp[amount] > amount ? -1 : dp[amount];
    }
};