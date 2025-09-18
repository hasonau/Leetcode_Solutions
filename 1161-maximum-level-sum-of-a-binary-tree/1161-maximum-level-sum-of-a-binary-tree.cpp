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
    int maxLevelSum(TreeNode* root) {
       
        queue<TreeNode*> q;
        q.push(root);
        int maxlevel=0;
        int currlevel=0;
        int currSum;
        int maxSum= INT_MIN;

        while(!q.empty()){
            int sizeofQueue=q.size();
            currlevel+=1;
            currSum=0;

            for(int i=0;i<sizeofQueue;i++){
                TreeNode* temp=q.front();
                currSum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
                q.pop();
            }
            if(currSum>maxSum){
                maxSum=currSum;
                maxlevel=currlevel;
            }
        }
        return maxlevel;

    }
};