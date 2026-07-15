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
    int ans = 0;
    void Inorder(TreeNode* root, int &K){
        if(root->left) Inorder(root->left, K);
        --K;
        if(K==0) ans= root->val;
        if(root->right) Inorder(root->right, K);
    }
    int kthSmallest(TreeNode* root, int k) {
         Inorder(root, k);
         return ans;
    }
};
