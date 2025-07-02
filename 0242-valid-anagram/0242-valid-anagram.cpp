// took me 6 minutes to write code,without any kind of logic time before,just straight code,
// cause i know what to do
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>hashmap;
        for(int i=0;i<s.size();i++){
            hashmap[s[i]]+=1;
        }
        for(int i=0;i<t.size();i++){
            hashmap[t[i]]-=1;
            if (hashmap[t[i]] == 0) {
                hashmap.erase(t[i]);
            }
        }
        if(hashmap.size()==0){
            return true;
        }
        return false;
    }
};