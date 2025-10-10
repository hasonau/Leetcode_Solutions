class Solution {
public:
    bool twoScenariosForEqualString(string s){
        bool seen[26] = {false};
        for(char c : s){
            if(seen[c - 'a']) return true;
            seen[c - 'a'] = true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {

        if(s.size()!=goal.size()) return false;
        if(s==goal) return twoScenariosForEqualString(s);

        vector<int>v;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]) v.push_back(i); 
        }
        if(v.size()!=2) return false;

        char temp=s[v[0]];
        s[v[0]]=s[v[1]];
        s[v[1]]=temp;
        return s == goal;


    }

};