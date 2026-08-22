class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n+1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        // loop only till n-1 to correspond to values in cost vector
        for(int i=2;i<n;i++){
            dp[i] =  min(dp[i-1] +cost[i], dp[i-2]+ cost[i]);
        }

        dp[n] = min(dp[n-1], dp[n-2]);// top remove the top value as top value has no cost its not last stair but end of stair the top ,
        return dp[n];
    }
};