class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
     queue<TreeNode*>q;
     vector<vector<int>>result;
     q.push(root);
     vector<int>v;
    while(q.size()>0){
        int saveQsize=q.size();

        for(int i=0;i<saveQsize;i++){
            TreeNode* temp=q.front();
            v.push_back(temp->val);
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        result.push_back(v);
        v.clear();
     }
    return result;   
    }

};