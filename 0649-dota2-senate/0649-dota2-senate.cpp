class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<char>q;
        int count_R=0;
        int count_D=0;

        for(char ch : senate){
            q.push(ch);
            if(ch =='R') count_R+=1;
            else count_D+=1;
        }
        cout<<"count of R"<<count_R<<endl;
        cout<<"count of D"<<count_D<<endl;
        int killed_D=0;
        int killed_R=0;
        cout<<"queue size is"<<q.size()<<endl;
        while(count_R>0 && count_D>0){
            char current=q.front();
            q.pop();
            if(current=='R'){
                if(killed_R==0){
                    killed_D++;
                    count_D--;
                    q.push('R');
                }
                else killed_R--;
            }
            else{
                if(killed_D==0){
                    killed_R++;
                    count_R--;                                        
                    q.push('D');
                }
                else killed_D--;
                
            }
        }
        if(count_R!=0) return "Radiant";
        return "Dire";
    }
};