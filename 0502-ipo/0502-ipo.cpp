class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>pairs;
        int n=profits.size();
        for (int i = 0; i < n; i++) {
            pairs.push_back({capital[i], profits[i]});
        }
        // now sort the pairs
        sort(pairs.begin(), pairs.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.first < b.first;
            }
        );
        // after sorting,we just go over the sorted list,and while doing so 
        // we update w with it,and also count k distinct values
        /////////////////////////
        // now while we are traversing over the pairs,we stop when our w is less than 
        // the pair's capital,at that moment,thing is we will actually now take out 
        // the max profit from the heap we be maintaining tilll now,and use that and just increase w,
        // which increases and then we move our loop till the point where there is again the case of 
        // our w being less than the capital,and then the max of heap will be our 
        // next result we add that and so on 
        priority_queue<int>maxHeap;
        int toStop=0;
        int i=0;
        for(int j=0;j<k;j++){
            while(i<pairs.size() && pairs[i].first<=w){
                maxHeap.push(pairs[i].second);
                i++;
            }
            if(maxHeap.empty()) break;
            w+=maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};
// 12:22