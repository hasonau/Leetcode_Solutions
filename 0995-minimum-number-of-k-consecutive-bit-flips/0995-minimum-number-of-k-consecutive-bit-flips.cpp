class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        vector<int> diffArr(nums.size()+1);
        int flipsCount = 0;
        int activeFlips = 0;

        for (int i = 0; i < nums.size(); i++) {
            activeFlips += diffArr[i];

            if ((nums[i] + activeFlips) % 2 == 0) {
                if (i + k > nums.size()) return -1;

                flipsCount++;
                diffArr[i] += 1;
                diffArr[i + k] -= 1;
                activeFlips++;
            }
        }
        
        return flipsCount;
    }
};