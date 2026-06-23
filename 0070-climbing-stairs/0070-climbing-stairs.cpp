// that is the top to bottom DP,cause it has memoization,although 
// many would say that's not actual DP

class Solution {
public:
    unordered_map<int,int>cache;

    int helper(int n){
        if(n==0 | n==1) return 1;
        if(cache.find(n)!=cache.end()) return cache[n];

        cache[n]=helper(n-1)+helper(n-2);
        return cache[n];
    }
    int climbStairs(int n) {

        return helper(n);
    }
};