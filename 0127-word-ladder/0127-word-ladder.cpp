class Solution {
public:
    int bfs(string beginWord, string endWord,unordered_set<string>& words,unordered_set<string>& visited){

        int beginLength = beginWord.length();
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        int level = 1;
        while(!q.empty()){
            int q_size = q.size();
            int counter = 1;
            while(counter <= q_size){
                string s = q.front();
                q.pop();
                if(s == endWord) return level;
                for(int i = 0; i < beginLength ; i++){
                    char currentChar = s[i];
                    for(int j = 0; j< 26 ; j++){
                        char newChar = 'a' + j;
                        if(newChar == s[i]) continue;
                        s[i] =  newChar;

                        if(words.find(s)!=words.end() && visited.find(s)==visited.end()) {
                            q.push(s);
                            visited.insert(s);
                        }
                    }
                    s[i] = currentChar;
                }
                counter++;
            }
            level++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> visited;
        unordered_set<string> words;

        for(auto word : wordList){
            words.insert(word);
        }
        
        if(words.find(endWord)==words.end()) return 0;

        return bfs(beginWord,endWord,words,visited);
    }
};