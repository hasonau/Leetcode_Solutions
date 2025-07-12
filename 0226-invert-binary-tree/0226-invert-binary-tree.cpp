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
    TreeNode* invertTree(TreeNode* root) {
    
    //  base case in recursion
    if (!root) return nullptr;

    // leaf node,so return without calling anything on it,be careful,
    // if one of the node's left or right has something we don't return,
    // because we will swap that one left/right side  with nullptr on the other side,as 
    // in the test case [1, 2, null, 3, null]
    if (!(root->left) && !(root->right)) return root;

    // recursion part here
    root->left=invertTree(root->left);
    TreeNode* temp=root->left;
    root->left=invertTree(root->right);
    root->right=temp;

    return root;
    }
}; 