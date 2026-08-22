class Solution {
public:
    bool canPartition(vector<int>& nums) {

        // Calculate the total sum of all elements
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, we cannot divide it into two equal parts
        if(sum % 2 != 0) {
            return false;
        }

        // We only need to find one subset with sum = total / 2
        int target = sum / 2;

        // dp[s] = true means we can form sum 's'
        // using the numbers processed so far
        vector<bool> dp(target + 1, false);

        // Sum 0 is always possible by taking no elements
        dp[0] = true;

        // Process each number one by one
        for(int num : nums) {

            // Go backwards so that each number is used only once
            for(int s = target; s >= num; s--) {

                // Either:
                // 1. We could already form sum 's'
                // OR
                // 2. We can form 's - num' and then add 'num'
                dp[s] = dp[s] || dp[s - num];
            }
        }

        // If target can be formed, the remaining elements
        // will automatically have the same sum
        return dp[target];
    }
};