class Solution {
public:

    bool checktwoHashmapequality(unordered_map<char,int>s1,unordered_map<char,int>s2){
        
        for (auto& [key, value] : s1) {
            if (s2.find(key) == s2.end() || s2[key] != value) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
     if (s1.size()>s2.size()) return false;
     unordered_map<char,int>s1Frequency;

     for(int i=0;i<s1.size();i++){
        s1Frequency[s1[i]]+=1;
    }   

    unordered_map<char,int>s2Frequency;
    int j=0;
    int i=0;

    while(j<s2.size()){
        if(s1Frequency.find(s2[j])==s1Frequency.end()){
            s2Frequency.clear();
            if(i!=j) i=j+1;
            else i++;
        }
        else{
            s2Frequency[s2[j]]+=1;
            if((j-i+1)==s1.size() && s1Frequency.size()==s2Frequency.size()){
                if (checktwoHashmapequality(s1Frequency,s2Frequency)){
                    return true;
                }
                else{
                    s2Frequency[s2[i]]-=1;
                    i++;
                }
            }
        }
        j++;
    }
    return false;

    }
};