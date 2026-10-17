class Solution {
public:
    bool carPooling(vector<vector<int>>& bookings, int capacity) {


         vector<int> diffArray(1001);

        for(int i = 0 ; i < bookings.size(); i++){
            
            int passengersCount = bookings[i][0];
            int start = bookings[i][1];
            int end = bookings[i][2];

            diffArray[start] += passengersCount;
            diffArray[end] -= passengersCount;
        }

        
        long long runningSum = 0;

        for (int i = 0; i < diffArray.size(); i++) {
            runningSum += diffArray[i];
            if(runningSum > capacity) return false;
            diffArray[i] = runningSum;
        }

        return true;
    }
};