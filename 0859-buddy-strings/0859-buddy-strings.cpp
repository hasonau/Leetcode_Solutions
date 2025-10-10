class Solution {
public:
    bool twoScenariosForEqualString(string s){
        unordered_set<char>unique;
        for(int i=0;i<s.size();i++){
            if(unique.find(s[i])!=unique.end()) return true;
            unique.insert(s[i]); 
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal) return twoScenariosForEqualString(s);
        int conflictCount=0;
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