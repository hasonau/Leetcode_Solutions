class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> countS;
        for (char ch : s){
            if(countS.find(ch)==countS.end()) countS[ch]=1;
            else countS[ch]+=1;
        }
        for (int i=0;i<s.size();i++){
            if(countS[s[i]]==1) return i; 
        }
        return -1;

    }
};