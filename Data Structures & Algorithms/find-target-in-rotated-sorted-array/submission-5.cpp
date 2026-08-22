class Solution {
public:
    int findpivot(vector<int>& nums , int n){
        int l =0 , r = n;
        while(l<r){
            int mid = l + (r-l) / 2;
            if(nums[mid]>nums[r]){
                l = mid+1;
            }
            else r = mid;
        }
        return r;
    }
    int binarysearch(int l , int r , vector<int>& nums , int target){
      int idx = -1 ;
          while(l<=r){
            int mid = l +(r-l) /2;
            if(nums[mid]==target){
                idx = mid;
                break;
            }
            else if (nums[mid]<target){
                l = mid+1;
            }
            else r = mid -1;
        }
        return idx;
    }
    int search(vector<int>& nums, int target) {
       int n = nums.size()-1;
       int pivot_index = findpivot(nums ,n);
       int index = binarysearch(0,pivot_index -1, nums , target);
       if(index !=-1){
        return index;
       }
       else {
        index = binarysearch(pivot_index , n , nums , target);
       }
       return index;
    }
};
