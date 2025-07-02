class Solution {
public:

    bool isPalindrome(string s){
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if (s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;

        while (left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else if(s[left]!=s[right]){

                //base condition 
                if (right-left==1) return true;


                if(s[left]==s[right-1]){
                    string temp = s.substr(left, right-left);
                    if(!isPalindrome(temp)){
                        if(s[right]==s[left+1]){
                             string temp = s.substr(left + 1, right - left);
                             return isPalindrome(temp);
                        }
                        return false;
                    }
                    else return true;
                }
                else if(s[right]==s[left+1]){
                   string temp = s.substr(left + 1, right - left);
                    if(!isPalindrome(temp)){
                        if(s[right]==s[left+1]){
                        string temp = s.substr(left, right-left);
                        return isPalindrome(temp);
                        }
                        return false;
                    }
                    else return true;
                }
                else return false;
            }

        }
        return true;
    }
};