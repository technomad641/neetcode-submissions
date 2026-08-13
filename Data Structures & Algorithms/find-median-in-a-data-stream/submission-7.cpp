class MedianFinder {
public:
    priority_queue< int , vector< int > > maxq;
    priority_queue< int , vector< int > , greater< int > > minq;
    MedianFinder() {
        
    }
    int neg(int x){
        if(x<0) return -x;
        return x;
    }
    
    void addNum(int num) {
        int p = num;
        if(maxq.empty() || num<=maxq.top()) maxq.push(p);
        else minq.push(p);
        while(neg(minq.size()-maxq.size())>1){
            if(minq.size()> maxq.size()){
                p = minq.top(); minq.pop(); maxq.push(p);
            }else{
                p = maxq.top(); maxq.pop(); minq.push(p);
            }
        }
    }
    
    double findMedian() {
        if(minq.size() == maxq.size()){
            return (double)(minq.top()+ maxq.top())/2.0;
        }
        if(minq.size()> maxq.size()) return minq.top();
        return maxq.top();
    }
};
