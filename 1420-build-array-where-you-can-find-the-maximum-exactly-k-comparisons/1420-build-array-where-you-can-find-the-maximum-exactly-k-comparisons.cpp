class Solution {
public:
    int K,M,N;
    static const int MOD= 1e9+7;
    int t[51][51][102];
    int recursive(int index,int cost,int max){
        if(index==N){
            if(cost==K) return 1;
            return 0;
        }
        if(t[index][cost][max+1]!=-1) return t[index][cost][max+1];
        int result=0;
        for(int i=1;i<=M;i++){
            if(i>max) result = (result+ recursive(index+1,cost+1,i)) % MOD;
            else result  = (result + recursive(index+1,cost,max)) % MOD;
        }
        return t[index][cost][max+1] = result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t,-1,sizeof(t));
        return recursive(0,0,-1);
    }
};