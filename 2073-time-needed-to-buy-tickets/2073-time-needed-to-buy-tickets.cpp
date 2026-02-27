class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int result=0;
        int value_at_k_index=tickets[k];
        for(int i=0;i<tickets.size();i++){
            // indexes on left side of k,they will run as much times as their value,except 
            // for those who are greater,they will run exact as the value at index k
            if(i<=k){
                if(tickets[i]<=value_at_k_index) result+=tickets[i];
                else result+=value_at_k_index;
            }
            // but for case,where i index will go past our k,it means,even if now there is a greater
            // value than the value at k,it would still run one less time the value of k,because 
            // that last time,k value will be eliminated and we return back,but smaller values will still run 
            // as much time as their own values
            else{
                if(tickets[i]<value_at_k_index) result+=tickets[i];
                else result+=value_at_k_index-1; // subtract 1 because after k buys last ticket, we stop,and 
                // bigger values after this index,they don't 
                // get the chance to execute this time,only smaller values execuate for all their values
            }
        }
        return result;
    }
};