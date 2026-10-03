class Solution {
public:
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
         
        vector<vector<int>> prefixSum;
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> result(rows,vector<int>(cols));
        prefixSum.resize(rows+1,vector<int>(cols+1,0));

        rows = prefixSum.size();
        cols = prefixSum[0].size();


        for(int i = 1 ;i < rows ; i++){
            for(int j = 1 ; j < cols ; j++){
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        rows -=1;
        cols-=1;

        for(int i = 0 ;i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                
                int ur = i - k;
                ur = max(0,ur);
                // if(ur < 0) ur = 0;

                int br = i + k;
                br = min(rows-1,br);
                // if(br >=rows) br = rows-1;

                int lc = j - k;
                lc = max(0,lc);
                // if(lc < 0) lc = 0;

                int rc = j + k;
                rc = min(cols-1,rc);
                // if(rc >= cols) rc = cols-1;
                

                result[i][j] = prefixSum[br+1][rc+1] - prefixSum[ur][rc+1] - prefixSum[br+1][lc] + prefixSum[ur][lc]; 
            }
        }

        return result;
    }
};