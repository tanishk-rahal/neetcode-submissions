class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1; 
        int zeroCount = 0;
        for(int i : nums){
            if(i !=0){
                product *= i;
            }
            else zeroCount++ ;
        }
        if(zeroCount>1){
            return vector<int>(nums.size(),0);
        }
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++){
            if(zeroCount==1){
                res[i]= (nums[i]==0)?product:0;
            }
            else res[i] = product / nums[i];
        }
        return res;
    }
};
