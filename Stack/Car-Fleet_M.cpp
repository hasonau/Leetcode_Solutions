// Comments added to the program on 28 June 2024.
// Variable names updated for better readability.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional> // for std::greater

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        // Map to store the time each car takes to reach the target
        std::unordered_map<int, double> positionToTimeMap;
        int fleetCount = 0; // Number of car fleets

        // Calculate the time for each car to reach the target and store in the map
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            positionToTimeMap[position[i]] = time;
        }

        // Sort positions in descending order
        std::sort(position.begin(), position.end(), std::greater<int>());

        double lastFleetTime = 0; // Time of the last car in the current fleet
        bool isSingleFleet = false; // Flag to handle single car fleet

        // Iterate through the sorted positions
        for (int i = 0; i < position.size(); i++) {
            // If there's only one car, it forms a single fleet
            if (position.size() == 1) return 1;

            if (i == 0) {
                // Initialize the time for the first car
                lastFleetTime = positionToTimeMap[position[i]];
            } else {
                // Compare current car's time with the last car's time in the current fleet
                if (positionToTimeMap[position[i]] <= lastFleetTime) {
                    // Current car joins the existing fleet
                    if (!isSingleFleet) {
                        isSingleFleet = true;
                    }
                    continue;
                } else {
                    // Current car forms a new fleet
                    if (i == position.size() - 1) {
                        lastFleetTime = positionToTimeMap[position[i]];
                        isSingleFleet = false;
                        fleetCount += 2; // Increment fleet count for the last car
                        break;
                    }
                    lastFleetTime = positionToTimeMap[position[i]];
                    fleetCount++;
                    isSingleFleet = false;
                }
            }
        }

        // Handle the case where the last set of cars forms a fleet
        if (isSingleFleet) {
            return fleetCount + 1;
        }
        return fleetCount;
    }
};

int main() {
    Solution solution;
    int target = 10;
    std::vector<int> position = {8, 3, 7, 4, 6, 5};
    std::vector<int> speed = {4, 4, 4, 4, 4, 4};

    int result = solution.carFleet(target, position, speed);
    std::cout << "Number of car fleets: " << result << std::endl;

    return 0;
}
