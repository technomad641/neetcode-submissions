class MinStack {
public:
    stack< int > st;
    stack< int > MIN_ST;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(MIN_ST.empty()) MIN_ST.push(val);
        else MIN_ST.push(min(val, MIN_ST.top()));
    }
    
    void pop() {
        st.pop();
        MIN_ST.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return MIN_ST.top();
    }
};
