/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void convert(queue< Node*>&q){
            int sz = q.size();
            Node* prev = NULL;
            for(int i=0;i<sz;i++){
                auto r = q.front(); q.pop();
                if(i ==0) prev = r;
                else{
                    prev->next = r;
                    prev = r;
                }
                q.push(r);
            }
            if(prev) prev->next = NULL;
    }
    Node* connect(Node* root) {
        queue< Node*> q;
        q.push(root);
        if(root == NULL) return root;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto x = q.front(); q.pop();
                if(x->left!= NULL) q.push(x->left);
                if(x->right!= NULL) q.push(x->right);
            }
            convert(q);

        }
        return root;
    }
};