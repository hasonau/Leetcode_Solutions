class KthLargest {
private:
    vector<int>v;
    int kthValue;
public:
    KthLargest(int k, vector<int>& nums) {
        kthValue=k;
        for(int num : nums){
            v.push_back(num);
        }
        sort(v.begin(),v.end());
    }
    int add(int val) {
        auto it = lower_bound(v.begin(), v.end(), val);
        v.insert(it,val);
        return v[v.size()-kthValue];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */