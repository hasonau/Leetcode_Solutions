class Solution {
public:
    vector<pair<int,int>> directions = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1}   // right
    };

    void bfs(vector<vector<int>>& grid,vector<vector<int>>& visited){
        int r = grid.size();
        int c= grid[0].size();

        queue<tuple<int, int, int>> q;
        q.push({0,0,0});
        visited[0][0] = 0;

        // cout << "\n===== BFS START =====\n";

        while(!q.empty()){

            int q_size = q.size();
            int counter = 0;

            // cout << "\nNew Level\n";
            // cout << "Queue size at start = " << q_size << "\n";

            while(counter < q_size){

                auto [i,j,bombUsed] = q.front();
                q.pop();

                // cout << "\n----------------------\n";
                // cout << "Counter = " << counter << " / " << q_size << "\n";
                // cout << "Popped : (" << i << "," << j << ") bombs = " << bombUsed << "\n";
                // cout << "visited[" << i << "][" << j << "] = " << visited[i][j] << "\n";

                if(bombUsed > visited[i][j]){
                    // cout << "SKIPPED because bombUsed > visited\n";
                    counter++;
                    continue;
                }

                for(auto direction : directions){

                    int new_i = i + direction.first;
                    int new_j = j + direction.second;

                    // cout << "\nChecking neighbour (" << new_i << "," << new_j << ")\n";

                    if(new_i < 0 || new_j < 0 || new_i >= r || new_j >= c){
                        continue;
                    }

                    // cout << "Grid value = " << grid[new_i][new_j] << "\n";
                    // cout << "Current visited = " << visited[new_i][new_j] << "\n";
                    // cout << "Condition checking : "
                    //     << bombUsed + 1 << " < " << visited[new_i][new_j] << "\n";

                    
                    int newValue = bombUsed + grid[new_i][new_j];

                    if((grid[new_i][new_j] && newValue < visited[new_i][new_j]) || (!grid[new_i][new_j] && newValue < visited[new_i][new_j])){
                            q.push({new_i,new_j,newValue});
                            visited[new_i][new_j] = newValue;
                    }
                    
                }
                counter++;
            }
            
        }
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int r = grid.size();
        int c= grid[0].size();

        vector<vector<int>> visited(r, vector<int>(c, INT_MAX));

        bfs(grid,visited);
        return visited[r-1][c-1];
    }
};