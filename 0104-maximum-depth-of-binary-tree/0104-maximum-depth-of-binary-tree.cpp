class Solution {
public:
    int maxDepth(TreeNode* root) {

            if(!root) return 0;

            int leftMax=maxDepth(root->left);
            int rightMax=maxDepth(root->right);

            return 1+(max(leftMax,rightMax));
    }
};