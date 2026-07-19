class Solution {
public:
    unordered_set<string>words;
    int t[301];
    bool recursive(int i,string& s){
        if(i>= s.size()) return true;

        if(t[i]!=-1) return t[i];
        string currentString="";
        int saveI=i;
        while(saveI<s.size()){
            currentString+=s[saveI++];
            if(words.find(currentString)!=words.end() && recursive(saveI,s)) return t[i] = true;
        }
        return t[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word : wordDict){
            words.insert(word);
        }
        memset(t,-1,sizeof(t));
        return recursive(0,s);
    }
};