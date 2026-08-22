class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0); // will store left nearest smaller (index)
        vector<int> right(n,0); // will store right nearest smaller (index)
        stack<int> s;

        //right smaller 
        for(int i = n-1;i>=0;i--){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.empty() ? n: s.top();//basically we are storing smaller value ki index instead or value and we set the default n agar current element ke right mai koi smaller value nahi hogi to boundary n ho jaye i.e laft element end;
            s.push(i);
        }
        while(!s.empty()){
            s.pop(); // to clear stack if any elements exist in it to re-use it 
        }
        // left smaller 
        for(int i=0;i<n;i++){
             while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        int ans =0 ;
        for(int i=0;i<n;i++){
            int width = right[i] - left[i] -1 ;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans ;
    }
};
