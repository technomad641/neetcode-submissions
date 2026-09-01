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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder ,int ins,int ine, int& pos) {
        if(pos< 0 || ins > ine ) return NULL;

        int rooindez = postorder[pos];
        TreeNode* root = new TreeNode(rooindez);
        --pos;
        for(int i=ins;i<=ine;i++){
            if(inorder[i]==rooindez){
                root->right = build(inorder, postorder, i+1, ine, pos);
                root->left = build(inorder, postorder, ins, i-1, pos);
                //break;
                return root;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int pos = postorder.size() - 1;
        return build(inorder, postorder, 0,inorder.size()-1,  pos);
    }
};