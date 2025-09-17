class Solution {
private:
    int sizeofPostOrder;
    unordered_map<int,int> nodeToindex;
public:
    void setSize(int n){
        this->sizeofPostOrder = n;
    }
    void makeMapping(vector<int> in){
        for (int i = 0; i < in.size(); i++){
            this->nodeToindex[in[i]] = i;
        }
    }

    TreeNode* makeTree(vector<int> &postorder, vector<int>& inorder, int &index, int startindexInorder, int endIndexInorder){
        if(startindexInorder > endIndexInorder || index < 0) return NULL;

        // cout << "post[index]==" << postorder[index] << endl;
        TreeNode* root = new TreeNode(postorder[index--]);
        int position = nodeToindex[root->val];

        // recursive calls
        root->right = makeTree(postorder, inorder, index, position+1, endIndexInorder);
        root->left  = makeTree(postorder, inorder, index, startindexInorder, position-1);

        return root;
    }
    // void display(vector<int>&array){
    //     for(int i=0;i<array.size();i++){
    //         cout<<"array["<<i<<"]=="<<array[i]<<endl;
    //     }
    // }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        setSize(postorder.size());
        makeMapping(inorder);
        int index = sizeofPostOrder - 1;
        return makeTree(postorder, inorder, index, 0, sizeofPostOrder-1);
    }
};