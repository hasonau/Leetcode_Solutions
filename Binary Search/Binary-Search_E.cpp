#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        while (L <= R) { // Changed to L <= R for the search to be valid
            int M = (L + R) / 2;
            if (target > nums[M]) {
                L = M + 1;
            } else if (target < nums[M]) {
                R = M - 1;
            } else {
                return M;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int result = solution.search(nums, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
