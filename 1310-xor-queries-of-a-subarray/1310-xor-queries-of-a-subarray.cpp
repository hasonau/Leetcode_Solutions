class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> prefixXor(arr.size()+1);

        int runningXor= 0;
        
        for(int i = 1 ;i <= arr.size();  i++){
            runningXor^= arr[i-1];
            prefixXor[i] = runningXor;
        }
       

        vector<int>result(queries.size());

        for(int i = 0 ; i < queries.size() ; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            result[i] = (prefixXor[end + 1] ^ prefixXor[start]);
        }

        return result;

    }
};