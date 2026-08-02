class Solution {
public:
    struct Node {
    int x, y;
    };

    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        int r = grid.size();
        int c = grid[0].size();

        if(i < 0 || i >= r || j < 0 || j >= c) return ;
        // visited[i][j] = false;
        // if it's itself 0,no exploration required
        if(grid[i][j] == '0') return;

        queue<Node>q;

        vector<Node>directions= {
            {-1,0},
            {0,-1},
            {1,0},
            {0,1}
        };

        q.push({i,j});
        // it keeps running untill all the levels in this first 
        // node are marked as false,and we are done with this one island
        while(!q.empty()){
            Node u = q.front();
            q.pop();
            visited[u.x][u.y] = true;
            for(Node direction : directions){
                
                int first = direction.x + u.x;
                int second = direction.y + u.y;
                if(first>=0 && first < r && second>=0 && second < c && !visited[first][second] && grid[first][second]=='1'){
                    q.push({first,second});
                    visited[first][second] =  true;
                }
            }
        }

    }




    int numIslands(vector<vector<char>>& grid) {
        // grid is our input representation
        // we can take out adjacency list,but for grids,it's mostly unnecessary,
        // not always,but this time we surely don't need adjacency list

        // we know grid[i][j] is a node
        // relation exists when two neighbours are both 1,valid nodes to be said precisely.
        int r = grid.size();
        int c = grid[0].size();

        // to know which nodes are visited
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        int count=0;
        // call bfs or dfs on each node,
        // using bfs here
        for(int i = 0;i < r; i++){
            for(int j = 0 ;j < c ;j ++){
            // if node not already visited or part of any island we have explored before
                if(!visited[i][j] && grid[i][j]== '1') {count++; bfs(i,j,grid,visited);}
            } 
        }
        return count;
    }
};