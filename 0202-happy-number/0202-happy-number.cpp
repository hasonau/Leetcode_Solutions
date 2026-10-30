class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int>  seen;
        seen.insert(n);

        while(true){
            int sum = 0 ;

            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            cout<<"sum is"<< sum<<endl;
            if(sum == 1) return true;
            if(seen.contains(sum)) return false;
            seen.insert(sum);
            n = sum;
        }
        return false;
    }
};