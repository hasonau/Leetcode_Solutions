class Solution {
private:
int maxResult=INT_MIN;
public:
    int helper(TreeNode* root){
        if(!root) return 0;

        int leftSide=helper(root->left);
        int rightSide=helper(root->right);
        maxResult=max(maxResult,leftSide+rightSide+root->val); // -1

        return max(leftSide,rightSide)+root->val>0 ?  max(leftSide,rightSide)+root->val : 0 ; //-1
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxResult;
    }
};