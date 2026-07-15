class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue< int, vector<int> >PQ;
        for(auto x: stones) PQ.push(x);
        while(!PQ.empty() && PQ.size()>1){
            int x1 = PQ.top(); PQ.pop();
            //if(!PQ.empty())
            int x2 = PQ.top(); PQ.pop();
            if(x1 == x2) continue;
            if(x1<x2) PQ.push(x2-x1);
            else PQ.push(x1-x2);
        }
        return PQ.empty()? 0: PQ.top();
    }
};
