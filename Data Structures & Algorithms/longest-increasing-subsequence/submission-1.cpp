class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i] = length of the longest increasing subsequence
        //         that ends at index i
        vector<int> dp(n, 1);

        // At minimum, every element itself is a subsequence of length 1
        int ans = 1;

        // Consider each element as the ending element of LIS
        for (int i = 1; i < n; i++) {

            // Check all elements before nums[i]
            for (int j = 0; j < i; j++) {

                // If nums[j] is smaller, we can add nums[i]
                // after the subsequence ending at nums[j]
                if (nums[j] < nums[i]) {

                    // dp[j] = previous LIS length
                    // +1   = add nums[i] to that subsequence
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            // Keep track of the maximum LIS found so far
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};