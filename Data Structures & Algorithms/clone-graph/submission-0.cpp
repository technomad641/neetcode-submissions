/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map< int, Node* > m;
    vector< int > vis;
    Node* dfs(Node* node){
        
        if(node==NULL) return NULL;
        
        if(m.find(node->val)!=m.end()) return m[node->val];
        
        Node* clone_node = new Node(node->val);
        m[node->val] = clone_node;
        for(auto x: node->neighbors){
            
                Node* p= dfs(x);
                clone_node->neighbors.push_back(p);
             
        }
        
        return clone_node;
    }
    Node* cloneGraph(Node* node) {
        //vis.resize(1000, 0);
        return dfs(node);
    }
};
