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
    int prev = INT_MIN;
    bool isValidBSTT(TreeNode* root, int x){
         if(root == NULL) return 1;
         bool isLeft = isValidBSTT(root-> left, root->val);
         if(prev!=INT_MIN && prev >=root->val) return false;
         prev = root->val;
         bool isRight = isValidBSTT(root-> right, root->val);
        return isRight && isLeft;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return 1;
        return isValidBSTT(root, root->val);
    }
};
