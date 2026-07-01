class Solution {
public:
    int climbStairs(int n) {
        if (n<=1) return 1;
        int left=1; int right =1;
        int i=2;
        while(i<=n){
            int temp = left+right;
            left=right;
            right=temp;
            i++;
        }
        return right;
    }
};