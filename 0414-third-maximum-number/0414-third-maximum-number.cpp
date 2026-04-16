class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int>pq(nums.begin(),nums.end());
        unordered_set<int>unS;
        int poppedvalue;
        int maximum_number=pq.top();
        while(pq.size()>0){
            poppedvalue=pq.top();
            pq.pop();
            unS.insert(poppedvalue);
            if(unS.size()==3) return poppedvalue;
        }
        return maximum_number;
    }
};