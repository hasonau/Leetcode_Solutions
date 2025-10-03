class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i=0;
        int result=0;
        while(tickets[k]!=0){
            if(i==tickets.size()) i=0;
            if(tickets[i]==0) {
                i++;
                continue;
                }
            tickets[i]-=1;
            i+=1;
            // start from first again
            result+=1;
        }
        return result;
    }
};