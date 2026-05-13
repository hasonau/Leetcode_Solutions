class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    priority_queue<int>maxHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        // maxHeap.push(num);
        // if(maxHeap.size()>(minHeap.size()+1)) {
        //     minHeap.push(maxHeap.top());
        //     maxHeap.pop();
        // }
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() < maxHeap.size()) return maxHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */