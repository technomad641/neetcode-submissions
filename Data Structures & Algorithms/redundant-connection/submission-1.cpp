class Solution {
public:
    vector< int > parent;
    int find(int a){
        if(a == parent[a]) return a;
        return find(parent[a]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int sz=edges.size();
        parent.resize(sz+1, 0);
        vector<int>ans;
        for(int i=1;i<=sz;i++) parent[i]=i;
        for(auto edge: edges){
            int a = edge[0];
            int b = edge[1];
            //cout<< find(a)<<" "<< find(b)<<endl;
            if(find(a)!= find(b)){
                parent[find(a)] = find(b);
            }else{
                return edge;
            }
        }
        return ans;
    }
};
