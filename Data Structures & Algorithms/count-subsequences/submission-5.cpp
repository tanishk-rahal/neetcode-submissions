class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1 )) ;
        // if t is empty there is only one way to form t from s is by choosing nothing 
        for(int i = 0;i<=n;i++){
            dp[i][0] = 1;
        }
        // if s is empty there is 0 ways to form t 
          for(int j = 1;j<=m;j++){
            dp[0][j] = 0;
        }
        for(int i = 1;i<=n;i++){
            for(int j =1 ; j<= m ;j++){
                if(s[i-1] == t[j-1]){
                     //add no. of ways by taking this character that match (diagonal value) or   skip cuurent value , (up cell value) 
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                                //diagonal  +  skip this char(up cell)
                }
                else dp[i][j] = dp[i-1][j] ;
                //if char do not match we skip current value 
            }
        }
        return dp[n][m];
    }
};
