class Solution {
public:
    int characterReplacement(string s, int k) {
    // base case
    if (s.size()==1) return 1;

    unordered_map<char,int>hashmap;
    int i=0;
    int j=1;
    hashmap[s[i]]+=1;
    int maximum=0;
    int result=0;
    while(j<s.size()){
        hashmap[s[j]]+=1;
        maximum=max(maximum,hashmap[s[j]]);
        if(((j+1-i)-maximum)<=k){
        result=max(result,j+1-i);
        }
        else{
            while((j+1-i)-maximum>k && i<j){
                hashmap[s[i]]-=1;
                i++;
            }
        }
        j++;
    }
    return result; 
    } 
};