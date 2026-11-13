class MyCircularQueue {
public:
    vector< int > q;
    int start = -1;
    int end = -1;
    int sz =0;
    int K =0;
    MyCircularQueue(int k) {
        q.resize(k, -1);
        K = k;
    }
    
    bool enQueue(int value) {
        if(sz == K) return false;
        ++sz;
        if(start == -1 && end == -1){
            ++start; ++end;
            q[end] = value;
        }else{
            end = (end+1)%K;
            q[end] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if(sz == 0) return false;
        start = (start+1)%K;
        //q[start] = value;
        --sz;
        return true;
        
    }
    
    int Front() {
        if(sz == 0) return -1;
        return q[start];
    }
    
    int Rear() {
        if(sz == 0) return -1;
        return q[end];
        
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == K;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */