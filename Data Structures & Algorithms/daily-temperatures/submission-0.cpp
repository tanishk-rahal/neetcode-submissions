class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        
        vector<int> res(temperatures.size() , 0) ;
        for(int i=0;i<temperatures.size();i++){
          while(!st.empty() && temperatures[i]>temperatures[st.top()]){
            int prevI = st.top();
            st.pop();
            res[prevI] = i - prevI;
          }
          st.push(i);
        }
        return res;
    }
};
