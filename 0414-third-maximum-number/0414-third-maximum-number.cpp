class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int firstMax=LONG_MIN;
        long int secondMax=LONG_MIN;
        long int thirdMax=LONG_MIN;

        int distinct_values=0;
        for(auto& num : nums){
            
            if(num==firstMax || num==secondMax || num==thirdMax) continue;

            distinct_values+=1;
            if(num>firstMax){
                thirdMax=secondMax;
                secondMax=firstMax;
                firstMax=num;
            }
            else if(num>secondMax){
                thirdMax=secondMax;
                secondMax=num;
            }
            else if(num>thirdMax){
                thirdMax=num;
            }
            else ;
        }

        // wrong way of returning,it will fail for [1,1,2],beacuse here there is no distinct third maxx,but it would still give answer as 
        // return nums.size()>2 ?  thirdMax : firstMax; 

        // correct way is to use somekind of way,to know distinct values
        return distinct_values>=3 ?  thirdMax : firstMax; 

    }
};