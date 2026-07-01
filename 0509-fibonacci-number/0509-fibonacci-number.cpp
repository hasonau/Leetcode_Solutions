class Solution {
public:
    int fib(int n) {
        if (n<=1) return n;
        
        int left=0;
        int right=1;
        int i=2;
        while(i<=n){
            int temp = left + right;
            left=right;
            right=temp;
            i++;
        }
        return right;
    }
};