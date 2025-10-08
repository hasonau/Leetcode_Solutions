class Solution {
public:
    TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int inOrderStartIndex,int inOrderEndIndex,int &preOrderIndex){
        
        // base cases
        if(inOrderStartIndex==inOrderEndIndex) return new TreeNode(preorder[preOrderIndex++]);
        if(preOrderIndex>=preorder.size() || inOrderStartIndex>inOrderEndIndex) return nullptr;


        int save=preorder[preOrderIndex];
        // rootIndex be used to find Root's index from Inorder
        int rootIndex=inOrderStartIndex;
        TreeNode* root= new TreeNode(save);

        // finding the index of root node
        while(true){
            if(inorder[rootIndex]==save) break;
            rootIndex++;
        }
        
        preOrderIndex+=1;
        root->left=helper(preorder,inorder,inOrderStartIndex,rootIndex-1,preOrderIndex);
        root->right=helper(preorder,inorder,rootIndex+1,inOrderEndIndex,preOrderIndex);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // no need for empty checks,it's always gonna have 1 value
        int preOrderIndex=0;
        return helper (preorder,inorder,0,preorder.size()-1,preOrderIndex);
    }
};