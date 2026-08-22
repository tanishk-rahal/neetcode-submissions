class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for(int i : numSet){
            if(numSet.find(i -1 )==numSet.end()){
            int lenght = 1;
            while(numSet.find(i +lenght)!= numSet.end()){
                lenght++;
            }
            longest = max(longest,lenght);
            }
        }
        return longest;
    }
};
