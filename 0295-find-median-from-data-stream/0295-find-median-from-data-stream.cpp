class MedianFinder {

public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
       
    }
    
    //////////////////////////////////////////////////
    //i was over  complicating it,so gpt told me to do it the right way,which is down there,
    // uncommented one
    // void addNum(int num) {
    //         if(maxHeap.empty() || maxHeap.top()>num){
    //             maxHeap.push(num);
    //         }
    //         else if (minHeap.size()==maxHeap.size() && !maxHeap.empty() && maxHeap.top()<=num){
    //             minHeap.push(num);
    //         }
    //         if(abs((int)(maxHeap.size() - minHeap.size()))>1){
    //             if(maxHeap.size()>minHeap.size()){
    //                 minHeap.push(maxHeap.top());
    //                 maxHeap.pop();
    //             }
    //             else{
    //                 maxHeap.push(minHeap.top());
    //                 minHeap.pop();
    //             }
    //         }
    //     }
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
       if(minHeap.size()>maxHeap.size()) return minHeap.top();
       else if(maxHeap.size()>minHeap.size()) return maxHeap.top();
       else return (maxHeap.top()+ minHeap.top())/2.0;
    }
};
