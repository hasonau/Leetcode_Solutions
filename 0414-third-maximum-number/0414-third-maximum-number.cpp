class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int maximum=INT_MIN;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            maximum=max(maximum,nums[i]);
            pq.push(nums[i]);
            if(pq.size()>3){
                int x=pq.top();
                pq.pop();
                s.erase(x);
            }
        }
        if(pq.size()==3) return pq.top();
        return maximum;
    }
};