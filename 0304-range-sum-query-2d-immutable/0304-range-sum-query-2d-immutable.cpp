class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefixSum.resize(rows+1,vector<int>(cols+1,0));

        rows = prefixSum.size();
        cols = prefixSum[0].size();

        for(int i = 1 ;i < rows ; i++){
            for(int j = 1 ; j < cols ; j++){
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + matrix[i-1][j-1];
                // cout<<"--"<<prefixSum[i][j];
            }
            cout<<endl;
        }
        for (int i = 0; i < prefixSum.size(); i++) {
            for (int j = 0; j < prefixSum[0].size(); j++) {
                cout << prefixSum[i][j] << " -- ";
            }
            cout << endl;
        }
    }
    
    int sumRegion(int ur, int lc, int br, int rc) {
        return prefixSum[br+1][rc+1] - prefixSum[ur][rc+1] - prefixSum[br+1][lc] + prefixSum[ur][lc]; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */