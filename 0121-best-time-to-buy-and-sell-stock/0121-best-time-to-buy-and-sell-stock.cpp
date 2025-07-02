// time it took me 
// for logic: 12 minutes
// for code : 5 minutes with minor issues
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()<2){
            return 0;
        }

        int left=0;
        int right=1;
        int maxProfit=0;

        // the only catch,or the trick or main relation between two pointers is that,
        // whenever we see a lesser value on right side,we will want to buy at that point,,so we move left 
        // pointer to that position,left pointer is actually the buytime,right pointer is sell time
        while(right<prices.size() && left<right){

            if(prices[left]>prices[right]){
                left=right;
                right++;
            }
            else{
                maxProfit=max(maxProfit,prices[right]-prices[left]);
                right++;
            }
        }
        return maxProfit;
    }
};