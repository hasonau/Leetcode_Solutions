class Solution {
public:
    int totalAmount;
    long t[13][10001];

    long recursive(int i,long currentSum,vector<int>& coins){
        // base case
        if(currentSum == totalAmount) return 0;
        if(i>= coins.size() || currentSum > totalAmount) return INT_MAX;
        
        if(t[i][currentSum]!=-1) return t[i][currentSum];

        long take = 1 + recursive(i,currentSum+coins[i],coins);
        long skip = recursive(i+1,currentSum,coins);

        return t[i][currentSum] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        memset(t,-1,sizeof(t));
        if(coins.size()==1) {
            if(amount % coins[0] == 0) return amount / coins[0];
            return -1;
        }
        
        totalAmount=amount;
        long result = recursive(0,0,coins);
        return result >= INT_MAX ? -1 : result; 
    }
};