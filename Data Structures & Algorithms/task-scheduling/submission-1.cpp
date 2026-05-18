class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map< char, int > freq;
        for(auto x: tasks){
            freq[x]++;
        }
        priority_queue< pair< int, int > , vector< pair< int, int > > > PQ;
        for(auto x: freq){
            PQ.push({x.second, x.second});
        }
        int time =0;
        queue< pair< int, int > > cooldown;
        while(!PQ.empty() || !cooldown.empty()){
            ++time;
            while(!cooldown.empty()){
                auto element = cooldown.front();
                if(time==element.second){
                    PQ.push({element.first,element.first});
                     cooldown.pop();
                }else break;
            }
            if(!PQ.empty()){
                pair< int, int > W = PQ.top(); PQ.pop();
                W.first--;
                if(W.first>0){
                    cooldown.push({W.first, n+time+1});
                }
            }
        }
        return time;
    }
};
