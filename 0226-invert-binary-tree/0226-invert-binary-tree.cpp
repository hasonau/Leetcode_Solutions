class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* leftSide= invertTree(root->left);
        TreeNode* rightSide= invertTree(root->right);
        
        root->left=rightSide;
        root->right=leftSide;
        return root;

    }
};