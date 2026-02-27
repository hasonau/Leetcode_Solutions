class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>line;
        for(int i=0;i<tickets.size();i++){
            line.push(make_pair(i,tickets[i]));
        }

        // all pushed till here
        int time_taken=0;
        while(true){
            int index,value;
            if(!line.empty()){
                pair<int,int> save = line.front();
                index= save.first;
                value=save.second;
                line.pop();
            }
            
            if((value-1)==0){
                 if(index==k) return time_taken+1;
            }
            else
                line.push(make_pair(index,value-1));
            
            time_taken+=1;
                    
        }
        return time_taken;
    }
};