//
// Created by muham on 11/07/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

//    MY SOLUTION
//        if (prices.empty()) return 0;
//
//        int minPrice = prices[0];
//        int maxProfit = 0;
//
//        for (int i = 1; i < prices.size(); ++i) {
//            if (prices[i] < minPrice) {
//                minPrice = prices[i];
//            } else {
//                maxProfit = max(maxProfit, prices[i] - minPrice);
//            }
//        }
//
//        return maxProfit;
//    }

//BETTER READABILITY METHOD.
            if (prices.empty()) return 0;

            int minPrice = prices[0];
            int maxProfit = 0;

            for (int i = 1; i < prices.size(); ++i) {
                // Update the minimum price if current price is lower
                minPrice = min(minPrice, prices[i]);
                // Calculate potential profit and update maxProfit
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }

            return maxProfit;
        }
};
int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(prices);
    cout << "Maximum profit: " << result << std::endl; // Output: 5
    return 0;
}