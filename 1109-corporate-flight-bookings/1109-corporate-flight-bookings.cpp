class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> diffArray(n+2);

        for(int i = 0 ; i < bookings.size(); i++){
            int start = bookings[i][0];
            int end = bookings[i][1];
            int value = bookings[i][2];

            diffArray[start] += value;
            diffArray[end + 1] -= value;
        }

        vector<int> result(n);
        int runningSum= 0;

        for(int i = 1; i <= n; i++){
            runningSum += diffArray[i];
            result[i - 1] = runningSum;
        }

        return result;
    }
};