class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){//opening bracket
                st.push(s[i]);
            }
            else {
                if(st.size()==0){
                    return false;

                }
                if((st.top() == '(' && s[i]==')') || 
                   (st.top() == '{' && s[i]=='}') || 
                   (st.top() == '[' && s[i]==']')   ) {
                    st.pop(); //match found
                }
                else return false ; //no valid match of bracket found
            }
        }
        if(st.size()==0){
            return true;
        }
        else return false;
    }
};
