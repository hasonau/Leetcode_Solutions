class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned="";
        for (int i=0;i<s.size();i++){
            
            if(s[i] >= 'a' && s[i] <= 'z') 
            {
                cleaned+=s[i];
                continue;

            }
            else if (s[i] >='A' && s[i] <='Z'){
                s[i]=tolower(s[i]);
                cleaned+=s[i];
            }
            else continue;
        }
        int left=0;
        int right=cleaned.size()-1;

        while (left<right){
            if(cleaned[left]==cleaned[right]){
                left++;
                right--;
                continue;
            }
             return false;
        }
        return true;
    }
};