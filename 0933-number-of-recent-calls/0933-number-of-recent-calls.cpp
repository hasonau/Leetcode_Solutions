class RecentCounter {
private:
    int l;
    int r;
    vector<int>nums;
    int recentRequests;
public:
    RecentCounter() {
        recentRequests=0;
        l=0;
        r=0;   
    }
    
    int ping(int t) {
            // first case,immediate return  
            if(nums.size()==0) {
                nums.push_back(t);
                return ++recentRequests;
            }
            nums.push_back(t);
            r++;
            int rightRange=nums[r]-3000;
            while(nums[l]<rightRange) l++;

            recentRequests= r-l+1;
            return recentRequests;

    }
};
