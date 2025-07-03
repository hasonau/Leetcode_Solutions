class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        int l = nums.size() - 1;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                l = nums.size() - 1;
                int k = j + 1;
                long long firsttwo = (long long)nums[i] + nums[j];

                while (k < l) {
                    long long sum_kl = (long long)nums[k] + nums[l];
                    if ((long long)target - firsttwo > sum_kl) {
                        k++;
                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }
                    }
                    else if ((long long)target - firsttwo < sum_kl) {
                        l--;
                        while (l < nums.size() && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    }
                    else {
                        result.push_back({ nums[i], nums[j], nums[k], nums[l] });
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }
        return result;
    }
};
