class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> diffArray(n+1);

        for(int i = 0 ; i < bookings.size(); i++){
            int start = bookings[i][0];
            int end = bookings[i][1];
            int value = bookings[i][2];

            diffArray[start-1] += value;
            diffArray[end] -= value;
        }

        vector<int> result(n);
        int runningSum= 0;

        for(int i = 0; i < diffArray.size() - 1; i++){
            runningSum += diffArray[i];
            result[i] = runningSum;
        }

        return result;
    }
};