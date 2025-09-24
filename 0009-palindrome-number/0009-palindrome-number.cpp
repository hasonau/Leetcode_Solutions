class Solution {
public:
    bool isPalindromeUtil(int n, int digits) {
        // base cases
        if (digits <= 1) return true;
        if (digits == 2) return n / 10 == n % 10;

        int power = (int)pow(10, digits - 1);
        int first = n / power;
        int last = n % 10;

        if (first != last) return false;

        // remove first and last digits
        int middle = (n % power) / 10;

        return isPalindromeUtil(middle, digits - 2);
    }

    bool isPalindrome(int n) {
        if (n < 0) return false;
        int digits = (n == 0) ? 1 : (int)log10(n) + 1;
        return isPalindromeUtil(n, digits);
    }
};
