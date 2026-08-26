class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // transforming word1[0...i-1] into an empty string requires i deletions.
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        // transforming an empty string into word2[0...j-1] requires j insertions.
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {  // if characters match do nothing
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // if char do not match we can perform three operations
                    dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
                }  // replace         //delete        //insert
            }
        }
        return dp[m][n];
    }
};