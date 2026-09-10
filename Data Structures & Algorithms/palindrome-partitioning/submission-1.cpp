class Solution {
public:
    bool isPalindrome(string s , int start , int end){
        while(start<end){
            if(s[start] != s[end]){
                return false;
            }
            end--;
            start ++;
        }
        return true;

    }
    void solve(string s ,vector<vector<string>> &ans ,vector<string> &current , int start ){
        if(start == s.size()){
            ans.push_back(current);
            return;
        }
        for(int i = start ;i<s.size() ; i++){
            if(isPalindrome(s , start ,i )){
                    current.push_back(s.substr(start , i - start +1));//adding current substring 
                     solve(s, ans, current, i+1);
                     current.pop_back();//backtracking step
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; 
        vector<string> current;
        solve(s ,ans , current , 0 );
        return ans;

    }
};
