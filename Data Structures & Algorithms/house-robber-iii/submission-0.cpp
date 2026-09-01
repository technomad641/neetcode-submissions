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
    unordered_map< TreeNode*, int > dp;
    int maxsum(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            return dp[root]= root->val;
        }
        if(dp.find(root)!= dp.end()) return dp[root];
        int option1 = root->val + (root->left?maxsum(root->left->left)+maxsum(root->left->right):0) + (root->right? maxsum(root->right->right)+maxsum(root->right->left):0);
        int option2 = (root->left ? maxsum(root->left):0) + (root->right ? maxsum(root->right):0);
        return dp[root] = max(option1, option2);
    }
    int rob(TreeNode* root) {
        return maxsum(root);
    }
};