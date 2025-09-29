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
    vector<vector<int>> levelOrder(TreeNode* root) {
       if(!root) return {};
       queue<TreeNode*> q;
       q.push(root);
       vector<vector<int>> result;
       vector<int>v;
       while(!q.empty()){
        int sizeofQ=q.size();
        for (int i=0;i<sizeofQ;i++){
            TreeNode* popRoot = q.front();
            v.push_back(popRoot->val);
            if(popRoot->left) q.push(popRoot->left);
            if(popRoot->right)  q.push(popRoot->right);
            q.pop();
        }
        result.push_back(v);
        v.clear();
    }
    return result;
    }
};