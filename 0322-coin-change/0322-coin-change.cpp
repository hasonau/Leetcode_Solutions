class Solution {
public:
    int total;
    int t[13][10001];
    long recursive(int n,long currentSum,vector<int>& coins){
        // base cases,always check sum first,and then check if n gone out of bound,maybe result is on 
        // that caes
        if(currentSum==total) return 0;
        if(currentSum > total || n==0) return INT_MAX;
        // memoization
        if(t[n][currentSum]!=-1) return t[n][currentSum];


        long take =1 + recursive(n,currentSum+coins[n-1],coins);

        // no need for this when take is long
        // if(take!=INT_MAX) take+=1;
        long skip = recursive(n-1,currentSum,coins);

        return t[n][currentSum] = min(take,skip);

    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(coins.size()==1){
            if(amount%coins[0]==0) return amount / coins[0];
            return -1;
        }


        total=amount;
        memset(t,-1,sizeof(t));
        int result=recursive(coins.size(),0,coins); 
        if ( result >=INT_MAX) return -1;
        return result;
    }
};