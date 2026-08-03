class Solution {
public:
    vector<pair<int,int>> directions = {
    {-1, 0}, // up
    {1,0},   // down
    {0,-1},  // left
    {0, 1},  // right
    {-1,-1}, // upLeft
    {-1, 1}, // upRight
    {1,-1},  // downLeft
    {1,1}    // downRight
    };
    
    int bfs(int minCost,vector<vector<int>>& grid,vector<vector<bool>>& visited){

        int r = grid.size();
        int c = grid[0].size();
        // the only case,that can now how problem is  start being the destination,so handle it first
        // now we know start is not our destination,so normal bfs
        if(r == 1 && c == 1) return 1;

        queue<pair<int,int>> q;
        q.push({0,0});

        int level=0;
        while(!q.empty()){
            level++;
            int queue_size= q.size();
            // exploring neighbours and pushing the ones that are not visited and valid as well
            int count = 0;
            while(count < queue_size){
                auto [i,j] = q.front();
                q.pop();
                visited[i][j] = true;

                for (auto direction : directions){
                    int new_i = i + direction.first;
                    int new_j = j + direction.second;

                    if(new_i >= 0 && new_j >= 0 && new_i < r && new_j < c && grid[new_i][new_j] != 1){

                        // if not visited,then push to queue and mark as visited
                        if(!visited[new_i][new_j]){
                            
                            // only case is,when new_i and new_j become the destination,bfs will surely give the minCost on that point
                            if(new_i == r-1 && new_j == c-1) return level+1;
                            visited[new_i][new_j] =  true;
                            q.push({new_i,new_j});
                        }
                    }
                }
                count++;
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c= grid[0].size();

        // if either the beginning or the ending cell is 1,we can't reach it at all
        if(grid[0][0] || grid[r-1][c-1]) return -1;


        vector<vector<bool>> visited(r,vector<bool>(c, false));

        return bfs(1,grid,visited);

    }
};