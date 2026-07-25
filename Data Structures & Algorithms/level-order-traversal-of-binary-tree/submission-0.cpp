/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue< TreeNode*> Q;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        Q.push(root);
        while(!Q.empty()){
            int sz = Q.size();
            vector< int> temp;
            for(int i=0;i<sz;i++){
                auto x = Q.front();
                Q.pop();
                temp.push_back(x->val);
                if(x->left!=NULL) Q.push(x->left);
                if(x->right!=NULL) Q.push(x->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
