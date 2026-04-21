class MedianFinder {

public:
    vector<int>v;
    MedianFinder() {
       
    }
    
    // void addNum(int num) {
    //     v.push_back(num);
    //     sort(v.begin(),v.end());
    // }
    void addNum(int num) {
            auto it = lower_bound(v.begin(), v.end(), num);
            v.insert(it, num);
        }
    double findMedian() {
        if(v.size()==1) return v[0];
        
        int theIndex=v.size()/2;
        if(v.size()%2==0){
            return (v[theIndex]+v[theIndex-1])/2.0;
        }
        if(v.size()%2==1){
            return v[theIndex];
        }
        return 0;
    }
};
