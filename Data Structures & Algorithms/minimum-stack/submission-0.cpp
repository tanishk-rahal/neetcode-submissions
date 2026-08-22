class MinStack {
public:
    stack<int> st;
    stack<int> minstk;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minstk.empty()){
            minstk.push(val);
        }
        else {
            minstk.push(min(val, minstk.top()));
        }
        
    }
    
    void pop() {
        st.pop();
        minstk.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        
        return minstk.top();
    }
};
