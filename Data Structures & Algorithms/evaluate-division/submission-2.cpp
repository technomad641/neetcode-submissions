class Solution {
public:
    unordered_map< string , vector<pair< string, double > > >gr;
    map< string , int> vis;
    map< string, double > dis;
    void dfs(string x, double ppp, string en){
        vis[x] = 1;
        dis[x] = ppp;
        if(x == en) return;
        int sz = gr[x].size();
        for(int i=0;i<sz;i++){
            if(vis.find(gr[x][i].first)== vis.end()){
              //  ppp*=gr[x][i].second;
               // if( gr[x][i].first == en ) r;
               double NN = ppp*gr[x][i].second;
                dfs(gr[x][i].first, NN, en);
            }
            
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int sz = equations.size();
        for(int i=0;i<sz;i++){
            gr[equations[i][0]].push_back({equations[i][1], values[i]});
            gr[equations[i][1]].push_back({equations[i][0], 1.000000/values[i]});
        }
        vector< double > ans(queries.size(), -1.0);
        for(int i=0;i<queries.size();i++){
            double ppp = 1.0000;
            string st = queries[i][0];
            string en = queries[i][1];
            if(gr.find(st)==gr.end() || gr.find(en)==gr.end()){
                 ans[i] = -1.0000000;
                  continue;
            }
            if(st == en) {// same start and destination
                
                ans[i] = 1.0000;
                continue;
            }
            dfs(st, ppp, en); // start and destination so we need a DFS here
            if(dis.find(en) == dis.end()) ans[i] = -1.0000000;
            else ans[i] = dis[en];
            vis.clear();
            dis.clear();
        }
        return ans;
    }
};