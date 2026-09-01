class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int ins, int ine, int& pos) {

        if (ins > ine) return NULL;

        int rootVal = postorder[pos--];

        TreeNode* root = new TreeNode(rootVal);

        int i = ins;
        while (i <= ine && inorder[i] != rootVal)
            i++;

        // Postorder is: LEFT -> RIGHT -> ROOT
        // Therefore process RIGHT first.
        root->right = build(inorder, postorder, i + 1, ine, pos);
        root->left  = build(inorder, postorder, ins, i - 1, pos);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, pos);
    }
};