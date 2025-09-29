class Solution {
private:
    int minimum=INT_MAX;
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        int leftSide=minDepth(root->left);
        int rightSide=minDepth(root->right);

        // Left and Right side,if any one is zero,we just send back the other,but 1 added.
        if(leftSide==0) return rightSide+1;
        if(rightSide==0) return leftSide+1;

        return min(leftSide,rightSide)+1;
    }
};