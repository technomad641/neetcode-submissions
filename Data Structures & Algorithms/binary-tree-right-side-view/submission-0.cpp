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
    vector<int> rightSideView(TreeNode* root) {
        vector< int > ans;
        if(root==NULL) return ans;
        queue< TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int sz = Q.size();
            for(int i=0;i<sz;i++){
                TreeNode* frontNode = Q.front(); Q.pop();
                if(i==0) ans.push_back(frontNode->val);
                if(frontNode->right) Q.push(frontNode->right);
                if(frontNode->left) Q.push(frontNode->left);
            }
            

        }
        return ans;

        
    }
};
