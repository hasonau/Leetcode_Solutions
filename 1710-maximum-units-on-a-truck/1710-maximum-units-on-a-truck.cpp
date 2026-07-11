class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int truckSize) {
        // sorting for the second value,beacuse that is the units per box,already given,no need to caluclate the ratio,like in fractional knapsack
        sort(nums.begin(),nums.end(),[](vector<int>& n1,vector<int>& n2){
            return n1[1] > n2[1];
        });
        int capacity=truckSize;
        int result=0;
        for(int i=0;i<nums.size();i++){
            
            int noOfBoxes=nums[i][0];
            int unitsperBox=nums[i][1];
            if(noOfBoxes <  capacity){
                result += (noOfBoxes * unitsperBox);
                capacity-=noOfBoxes;
            }
            else{
                result += (capacity * unitsperBox);
                break;                
            }
        }
        return result;


        
    }
};