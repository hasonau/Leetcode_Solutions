class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int leftSide=maxDepth(root->left);
        int rightSide=maxDepth(root->right);

        return max(leftSide,rightSide)+1;
    }
};