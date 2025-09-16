class Solution {
private:
    int sizeofPreOrder;
    unordered_map<int,int>nodeToindex;
public:
    void setSize(int n){
        this->sizeofPreOrder=n;
    }
    void makeMapping(vector<int>in){
        for (int i=0;i<in.size();i++){
            this->nodeToindex[in[i]]=i;
        }
    }

    TreeNode* makeTree(vector<int>preorder,vector<int>inorder,int &index,int startindexInorder,int endIndexInorder){
        if(startindexInorder>=endIndexInorder || index>=this->sizeofPreOrder) {
            cout<<"END OF RECURSION"<<endl;
            return NULL;
        }

        // printing for debugging
        cout << "preorder: " << preorder[index] << endl;
        cout << "inorder: " << inorder[startindexInorder] << endl;
        cout << "index: " << index << endl;

        // preorder =
        // [3,9,20,15,7]
        // inorder =
        // [9,3,15,20,7]

        TreeNode* root=new TreeNode(preorder[index++]);
        cout<<"root vall is : "<<root->val<<endl;
        int position=nodeToindex[root->val];
        cout << "position: " << position << endl;
        cout<<"ENDDDDDDDDDDDDDDD"<<endl;
        // recursive calls
        root->left=makeTree(preorder,inorder,index,startindexInorder,position);
        root->right=makeTree(preorder,inorder,index,position+1,endIndexInorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        setSize(preorder.size());
        makeMapping(inorder);
        int index=0;
        return makeTree(preorder,inorder,index,0,sizeofPreOrder);
        
    }
};