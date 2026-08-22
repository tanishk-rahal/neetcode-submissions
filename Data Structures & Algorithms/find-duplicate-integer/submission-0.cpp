class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1;
        while(l<r){
            int mid = l + (r-l) / 2;
        int lessOrEquals = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                lessOrEquals++;
            }
        }
        if(lessOrEquals>mid){
            r = mid;
        }
        else l = mid+1;

        }
        return l ;
    }
};
