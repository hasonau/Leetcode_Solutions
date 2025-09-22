class Solution {
public:
    double helper(double x,int n){
        if (n==1) return x;

        double res=helper(x,n/2);
        return n%2==1 ? res*res*x : res*res;
    }
    double myPow(double x, int n) {
        // i forgot these two,on the second stage
        if(x==0) return x;
        if(n==0) return 1;

        double res=helper(x,abs(n));
        return n<0 ? 1/res : res;
    }
};