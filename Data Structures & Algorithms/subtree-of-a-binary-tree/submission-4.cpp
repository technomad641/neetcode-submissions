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
    bool isSame(TreeNode* a, TreeNode* b){
        if(a== NULL && b == NULL) return true;
        if(a== NULL && b!=NULL) return false;
        if(b== NULL && a!=NULL) return false;
        //if(a->val != b->val) return false;
        return (a->val == b->val) && isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            if(subRoot == NULL) return true;
            return false;
        }
        return isSame(root,subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);
    }
};
