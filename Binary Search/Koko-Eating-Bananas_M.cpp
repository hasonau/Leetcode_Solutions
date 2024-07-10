//
// Created by muham on 02/07/2024.
//
#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element
#include <cmath> // for std::ceil

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max_element = std::max_element(piles.begin(), piles.end());
        int maximum = *max_element;
        int low = 1; // minimum speed should be at least 1
        int high = maximum;
        int result = high; // initialize result to the highest possible value

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow with (low + high) / 2
            long long temp_hour_used = 0;

            // Calculate the total hours needed with current speed mid
            for (int i = 0; i < piles.size(); i++) {
                temp_hour_used += (piles[i] + mid - 1) / mid; // This is equivalent to std::ceil((double)piles[i] / mid)
            }

            if (temp_hour_used <= h) {
                // If the current speed allows finishing within h hours, update the result
                result = mid;
                high = mid - 1; // try for a smaller value
            } else {
                low = mid + 1; // increase the speed
            }
        }

        return result;
    }
};


int main() {
    Solution solution;
    vector<int> piles = {873375536,395271806,617254718,970525912,634754347,824202576,694181619,20191396,886462834,442389139,572655464,438946009,791566709,776244944,694340852,419438893,784015530,588954527,282060288,269101141,499386849,846936808,92389214,385055341,56742915,803341674,837907634,728867715,20958651,167651719,345626668,701905050,932332403,572486583,603363649,967330688,484233747,859566856,446838995,375409782,220949961,72860128,998899684,615754807,383344277,36322529,154308670,335291837,927055440,28020467,558059248,999492426,991026255,30205761,884639109,61689648,742973721,395173120,38459914,705636911,30019578,968014413,126489328,738983100,793184186,871576545,768870427,955396670,328003949,786890382,450361695,994581348,158169007,309034664,388541713,142633427,390169457,161995664,906356894,379954831,448138536}; //312884470
    int h = 943223529;
    int result = solution.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;
    return 0;
}