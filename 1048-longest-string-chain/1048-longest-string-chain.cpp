class Solution {
public:
    int t[1001][1001];

    bool isChain(const string& s1,const string& s2){
        if(s2.size() - s1.size() != 1) return false;
        int i=0,j=0;
        int misMatch=0;
        while(i< s1.size()){
            if(s1[i] == s2[j]){
                i++; j++;
                continue;
            }
            misMatch++;
            j++;
            if( misMatch >= 2) return false;
        }
        return true;
    }

    int recursive(vector<string>& words,int i,int lastInd){
        if(i >= words.size()) return 0;
        if(t[i][lastInd+1]!=-1) return t[i][lastInd+1];
        
        int left=0;
        if(lastInd==-1 || isChain(words[lastInd],words[i])) left = 1 + recursive(words,i+1,i);
        int right = recursive(words,i+1,lastInd);
        
        return t[i][lastInd+1] = max(left,right);
    }

    int longestStrChain(vector<string>& words) {
        if(words.size()==1) return 1;

        sort(words.begin(),words.end(),[](const string& s1,const string& s2){
            return s1.size() < s2.size();
        });
        memset(t,-1,sizeof(t));
        // recursion
        return recursive(words,0,-1);
    }
};