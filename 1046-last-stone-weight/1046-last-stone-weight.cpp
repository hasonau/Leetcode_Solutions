class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        // now that max is on top,we can pop two,and perform things,right
        while(pq.size()>1){
            int y= pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x<y) pq.push(y-x);
            else ;
            cout<<"x and y are " <<x <<" "<<y<<endl;
        }
        return pq.size()==1 ?  pq.top() : 0;
    }
};