// codestorywithmik solution,not mine
class Solution {
public:
    //Approach-1 (Recusrion+Memoized)
    int t[13][10001];
    int minCoinsToGetAmount_Memoized(vector<int>& coins, int amount, int n) {
        if(t[n][amount] != -1)
            return t[n][amount];
        
        //if there is no coin, then may be if I take infinite coins, I can reach to amount
        if(n == 0)
            return t[n][amount] = INT_MAX-1;
        
        //if amount is 0, minimum coins to get 0 is 0
        if(amount == 0)
            return t[n][amount] = 0;
        
        //if there is only one coin, then we can reach to amount only if it's divisible
        //by that one coin value. Else it's not possible (hence returing invalid INT_MAX-1)
        if(n == 1) {
            if(amount%coins[n-1] == 0)
                return t[n][amount] = amount/coins[n-1];
            else
                return t[n][amount] = INT_MAX-1;
        }
        
        if(coins[n-1] <= amount)
            return t[n][amount] = min( 1+minCoinsToGetAmount_Memoized(coins, amount-coins[n-1], n), //unbounded knapsack
                         minCoinsToGetAmount_Memoized(coins,  amount, n-1));
        else
            return t[n][amount] = minCoinsToGetAmount_Memoized(coins, amount, n-1);
    }
    
    int coinChange(vector<int>& coins, int amount) {
    memset(t, -1, sizeof(t));
    int ans = minCoinsToGetAmount_Memoized(coins, amount, coins.size());
    
    return (ans >= INT_MAX - 1) ? -1 : ans;
}
};