class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // base cases
        if (s.size()==0) return 0;
        if (s.size()==1) return 1;


        unordered_set<int>longestString;
        int i=0;
        int j=1;
        int result=1;
        int count=1;
        longestString.insert(s[i]);
        while(j<s.size()){
            if(longestString.find(s[j])==longestString.end()){
                longestString.insert(s[j]);   
            }
            else{
                while(longestString.find(s[j])!=longestString.end()){
                    count-=1;
                    longestString.erase(s[i]);
                    i++;
                }
                longestString.insert(s[j]); 
            }
            j++;
            count+=1;
            result=max(count,result);
        }

        return result;
    }
};