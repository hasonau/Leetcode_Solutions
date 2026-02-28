class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        // to apply my logic,we must need to do sorting,nlogn,using built in,
        // that's not the question here,that's why
        sort(deck.begin(),deck.end());

        int set_values=0;
        int deck_iterator=0,result_iterator=0;
        bool flag_to_place_or_not=true; // we always place the very first value on the first 0th 
        // index,it's place will be always that one
        vector<int> result(deck.size());
        do{
            if(result[(result_iterator%deck.size())]!=0) 
                result_iterator+=1;
            else{
                if(flag_to_place_or_not){
                    // we are allowed to place value there,value is taken from deck
                    result[(result_iterator%deck.size())]=deck[deck_iterator];
                    flag_to_place_or_not=false;
                    result_iterator+=1;
                    deck_iterator+=1;
                    set_values+=1;
                }
                else{
                    //  here we just have to skip that place,because this value 
                    // goes to next available place,not this one
                    result_iterator+=1;
                    flag_to_place_or_not=true;
                }
            }
        }while(set_values!=deck.size());
        return result;
    }
};