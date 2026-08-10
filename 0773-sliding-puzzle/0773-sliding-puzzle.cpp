class Solution {
public:
    // vector<pair<int,int>> directions ={
    //     {0,-1}, // left
    //     {0,1}, // right
    //     {-3,0}, // up 
    //     {3,0} // down
    // };

    int bfs(int zeroIndex,string& s,unordered_set<string>& visited){
        
        string target ="123450";

        queue<pair<string,int>> q;
        q.push({s,zeroIndex});
        visited.insert(s);

        vector<int> directions = {1,-1,3,-3};

        int level = 0;
        while(!q.empty()){

            int counter = 0;
            int q_size = q.size();

            while(counter < q_size){

                auto [s,index] = q.front();
                q.pop();
                if(s == target) return level;

                
                // left,right,up,down
                for(int direction : directions){
                    
                    int new_index = index + direction;

                    // if new indices are out of bound,just don't go ahead creating string
                    if(new_index < 0 || new_index >= 6 ) continue;

                    // for right edges,we skip right direction,for left edges we skip left direction work
                    if ((index % 3 == 2 && direction == 1) ||
                        (index % 3 == 0 && direction == -1))
                        continue;

                    // process now

                    // create new string for this direction
                    string next = s;

                    // create the new string
                    swap(next[index],next[new_index]);

                    // already visited
                    if(visited.contains(next)) continue;

                    // push here
                    q.push({next,new_index});
                    visited.insert(next);

                }

                counter++;
            }

            level++;    
        }
        return -1;
        
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string s;
        int zeroIndex;
        for(auto b : board){
            for (int c : b){
                s+= '0' + c ;
                if(c == 0) zeroIndex = s.size()-1;
            }
        }
        
        unordered_set<string> visited;

        // if grid/board is already equal to target
        if(s == "123450") return 0;


        return bfs(zeroIndex,s,visited);
    }
};