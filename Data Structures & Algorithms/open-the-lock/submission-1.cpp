class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set< string > ends;
        for(auto x: deadends) ends.insert(x);
       
        string start = "0000";
         if(ends.find(start)!=ends.end()) return -1;
        queue< pair< string, int > > Q;
        unordered_map< string, int > vis;
        Q.push({start, 0});
        vis[start]=1;
        while(!Q.empty()){
            auto X = Q.front(); Q.pop();
            string P = X.first;
            if(P==target) return  X.second;
            //vis[start]=1;
            for(int i=0;i<4;i++){
                int x = P[i]-'0';
                int forward = (x+1)%10;
                int backward = (x-1+10)%10;
                string forwardS =P; forwardS[i]=forward+'0';
                string backwardS =P; backwardS[i]=backward+'0';
                if(vis.find(forwardS)==vis.end() && ends.find(forwardS)==ends.end()){
                    Q.push({forwardS, X.second+1});
                    vis[forwardS]=1;
                }
                if(vis.find(backwardS)==vis.end() && ends.find(backwardS)==ends.end()){
                    Q.push({backwardS, X.second+1});
                    vis[backwardS]=1;
                }
            }
        }
        return -1;
    }
};