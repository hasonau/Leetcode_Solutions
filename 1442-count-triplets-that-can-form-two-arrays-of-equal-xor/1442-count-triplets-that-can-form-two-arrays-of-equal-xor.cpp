class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int count = 0;

        for(int i = 0 ;i < arr.size(); i++){
            int runningXor = arr[i];
            for(int k = i+1; k < arr.size(); k++){
                runningXor ^= arr[k];
                if(runningXor == 0 ) {
                    count = count + (k - i);
                }
            }
        }
        return count;
    }
};