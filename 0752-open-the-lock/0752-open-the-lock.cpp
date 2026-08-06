class Solution {
public:
    unordered_set<string> NotAllowed;

    string T ;
    
    int bfs(vector<bool>& visited){
        // if start itself is deadend, no need to explore
        if(NotAllowed.find("0000")!=NotAllowed.end()) return -1;

        queue<string> q;
        q.push("0000");
        visited[stoi("0000")] = true;
        int level =0;

        while(!q.empty()){
            
            int q_size = q.size();
            int counter = 0;
            while(counter < q_size){
                string s = q.front();
                q.pop();
                // the one we are trying to explore,can be target already
                if(s == T) return level;
                for(int i = 0; i < 4 ;i++){
                    string currentString = s;
                    // gives the desired character
                    char digit = s[i];

                    // increment wraparound,10 modulus for (9+1 case), and make it character again,and assign back to string
                    char next = ((digit - '0' + 1) % 10) + '0';       
                    // decrement with wraparound needs extra ten,in order to avoid -1 in case of (0 - 1)
                    char prev = (((digit - '0' - 1 + 10) % 10) + '0');       

                    s[i] = next;
                    if(NotAllowed.find(s)==NotAllowed.end() && !visited[stoi(s)]){
                        visited[stoi(s)] = true;
                        q.push(s);
                    }

                    s[i] = prev;
                    if(NotAllowed.find(s)==NotAllowed.end() && !visited[stoi(s)]){
                        visited[stoi(s)] = true;
                        q.push(s);
                    }
                    s = currentString;
                }
                counter++;
            }
            level++;
        }
        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        T = target;
        // create deadends set,for fast lookups later in bfs
        for(auto deadend :  deadends){
            NotAllowed.insert(deadend);
        }
        vector<bool>visited(10000,false);
        // no augmentation required
        return bfs(visited);
    }
};