class Solution {
public:
    vector<pair<int, int>> directions = {
    {-1, 0}, // Up
    {1, 0},  // Down
    {0, -1}, // Left
    {0, 1}   // Right
    };

    int bfs(int k,vector<vector<int>>& grid , vector<vector<vector<bool>>>& visited){
        int r= grid.size();
        int c=grid[0].size();

        queue<tuple<int, int, int>> q;
        q.push({0,0,k});
        visited[0][0][k] = true;
        int level = 0;
        while(!q.empty()){
            int queue_size = q.size();
            int counter = 0;
            while(counter < queue_size){
                auto [i, j, remK] = q.front();
                q.pop();

                    for(auto direction : directions){
                        int new_i = i + direction.first;
                        int new_j = j + direction.second;

                        int newRemK = remK;

                        if(new_i < 0 || new_i >= r || new_j < 0 || new_j >= c) continue;

                        if(grid[new_i][new_j] == 1){
                            if(remK == 0) continue;   // cannot enter wall
                            newRemK = remK - 1;
                        }

                        if(!visited[new_i][new_j][newRemK]) {

                            if(new_i == r-1 && new_j == c-1)
                                return level + 1;

                            visited[new_i][new_j][newRemK] = true;
                            q.push({new_i, new_j, newRemK});
                        }
                }
                counter++;
            }
            level++;
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        // no need of checks for start and end cell,the constraints are told they handle themselves
        // it's always 0 on both of those,but sometimes it's better not to trust them and put your validations still so,
        int r=grid.size();
        int c= grid[0].size();

        if(grid[0][0]==1 || grid[r-1][c-1]==1) return -1;
        // handle edge case of 1 by 1 matrix
        if(r==1 && c==1) return 0;

        vector<vector<vector<bool>>> visited(r,vector<vector<bool>>(c, vector<bool>(k + 1, false)));
        return bfs(k,grid,visited);
        
    }
};