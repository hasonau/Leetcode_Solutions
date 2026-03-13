class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int> windowWithMax;
        for(int i=0;i<nums.size();i++){
            if(!windowWithMax.empty() && windowWithMax.front()<=i-k){ // here we compare indexes,if out of range,just pop it
                windowWithMax.pop_front();
            }
            while(!windowWithMax.empty() && nums[windowWithMax.back()]<nums[i]){ // here we compare values,and 
            // then either pop or not
                windowWithMax.pop_back();
            }
            windowWithMax.push_back(i); // index pushing

            if((i+1)>=k) result.push_back(nums[windowWithMax.front()]);
        }
        return result;
    }
};