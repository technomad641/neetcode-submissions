class MyStack {
public:
    queue< int > Q1;
    queue< int > Q2;
    MyStack() {
        
    }
    
    void push(int x) {
        
        if(Q1.empty()){
            Q1.push(x);
            while(!Q2.empty()){
                Q1.push(Q2.front()); Q2.pop();
            }
             
        }else{
             Q2.push(x);
            while(!Q1.empty()){
            Q2.push(Q1.front()); Q1.pop();
        }
           
        }
    }
    
    int pop() {
        int p = -1;
        if(Q1.empty()){
            p = Q2.front(); Q2.pop();
        }else{
            p = Q1.front(); Q1.pop();
        }
        return p;
    }
    
    int top() {
        if(Q1.empty()){
            return Q2.front();
        }
        return  Q1.front();
    }
    
    bool empty() {
        return Q1.empty() && Q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */