//
// Author: [Umair]
// Date: 2024-06-30
// Commented BY GPT  for the largestRectangleArea algorithm
//
#include <iostream>
#include <vector>
#include <stack>


class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> indices; // Stack to store indices of heights array
        int maxArea = 0; // Variable to store the maximum area

        for (int i = 0; i <= heights.size(); i++) {
            // If the stack is empty, push the current index
            if (indices.empty()) {
                indices.push(i);
            }
                // If the current height is greater than or equal to the height at the top index of the stack, push the current index
            else if (i < heights.size() && heights[i] >= heights[indices.top()]) {
                indices.push(i);
                continue;
            }
                // If the current height is less than the height at the top index of the stack, calculate the area for each popped height
            else {
                while (!indices.empty() && (i == heights.size() || heights[i] < heights[indices.top()])) {
                    int height = heights[indices.top()]; // Height of the rectangle
                    indices.pop();
                    int width = indices.empty() ? i : i - indices.top() - 1; // Width of the rectangle
                    maxArea = std::max(maxArea, height * width); // Update max area if the current area is larger
                }
                indices.push(i); // Push the current index after processing the smaller height
            }
        }
        return maxArea;
    }
};

int main(){
    Solution s;
    std::vector<int> v{7,1,7,2,2,4};
    std::cout<< s.largestRectangleArea(v);
}