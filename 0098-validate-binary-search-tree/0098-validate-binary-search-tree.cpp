class Solution {
public:
    bool helper(TreeNode* root, long long left, long long right) {
        if (!root) return true;

        if (!(root->val > left && root->val < right)) return false;
        // another way of writing same thing
        // if (root->val <= left || root->val >= right) return false;

        return helper(root->left, left, root->val) &&
               helper(root->right, root->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
        // this below won't work,although it seems it would
        // return helper(root,long(INT_MIN)+1,long(INT_MAX)+1);
    }
};
