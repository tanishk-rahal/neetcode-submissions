class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(auto i : nums){
            count[i]++;
        }
        vector<pair<int, int>> arr;
        for( auto p : count){
            arr.push_back({p.second , p.first});
        }
        sort(arr.begin(), arr.end() , greater<pair<int,int>>());

        vector<int> res;
        for(int i=0;i<k;i++ ){
            res.push_back(arr[i].second);
        }
        return res;
    }
};
