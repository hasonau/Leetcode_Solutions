class Solution {
public:
    long long t[100001][2];
    long long recursive(vector<int>& nums,int index,int evenOddCheck){
        evenOddCheck %=2;
        // base case
        if(index>=nums.size()) return 0;
        if(t[index][evenOddCheck]!=-1) return t[index][evenOddCheck];
        // recursive calls
        long long temp=0;
        if(evenOddCheck) temp= -nums[index];
        else temp=nums[index];

        long long left = temp + recursive(nums,index+1,evenOddCheck+1); // left branch call,we move index as well
        
        long long right = recursive(nums,index+1,evenOddCheck);
        return t[index][evenOddCheck] = max(left,right);
    }


    long long maxAlternatingSum(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int i=0;
        return recursive(nums,0,0);
        
    }
};