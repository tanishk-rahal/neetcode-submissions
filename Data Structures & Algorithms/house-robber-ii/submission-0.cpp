class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1){
            return nums[0];
        }
        //we break the problem in two sub parts , in one we rob first house so we can rob seccond house as array is circular now (0,n-1)
        // and in second part we rob the last house so we cant rob the first house now (1,n); 
        return max(helper(0,n-1,nums) , helper(1,n,nums));
    }

    int helper(int start , int end , vector<int>& nums){
       int prev2 =0;//prev2 = nums[i-2]
       int prev1 = 0;//prev1 = nums[i-1]
       for(int i = start; i< end; i++){
        int curr = max(prev1 , prev2+nums[i]);
        prev2 = prev1;//This is just sliding the DP values forward.
        prev1= curr;//prev2 will become nums[i-1] and prev1 = current value nums[i];
       }
       
       return prev1;

    }
};