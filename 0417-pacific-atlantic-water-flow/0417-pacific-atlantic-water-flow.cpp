class Solution {
public:
    const vector<pair<int, int>> directions = {
    {-1, 0},  // up
    {1, 0},   // down
    {0, -1},  // left
    {0, 1}    // right
    };
    void dfs(int i,int j,vector<vector<pair<bool,bool>>>& visited,vector<vector<int>>& grid,bool pacificOcean){
        int r = grid.size();
        int c = grid[0].size();
        // visited[i][j] = true;
        // theOcean.insert({})
        // handling both in one visited set
        if(pacificOcean) visited[i][j].first = true;
        else visited[i][j].second = true;

        for(auto direction : directions){
            int new_i = i + direction.first;
            int new_j = j + direction.second;

            if(new_i >= r || new_i < 0 || new_j < 0 || new_j >= c) continue;
            if((pacificOcean && visited[new_i][new_j].first)  || (!pacificOcean && visited[new_i][new_j].second)) continue;

            if(grid[new_i][new_j] >= grid[i][j]) dfs(new_i,new_j,visited,grid,pacificOcean);
        }

        return ;

    }



    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int r = grid.size();
        int c= grid[0].size();


        vector<vector<pair<bool,bool>>> visited (r, vector<pair<bool, bool>>(c, {false, false}));

        // unordered_set<pair<int,int>> pacificOcean;

        int i=0;

        // first row only---> TOP MOST ROW
        for(int j=0;j < c;j++){
            if(!visited[i][j].first) dfs(i,j,visited,grid,true);
        }
        // first column----> LEFT MOST COLUMN
        int j = 0;
        for(int i=0;i < r;i++){
            if(!visited[i][j].first) dfs(i,j,visited,grid,true);
        }

        // unordered_set<pair<int,int>> atlanticOcean;
        // visited.clear();

        // last row----> BOTTOM MOST ROW
        i = r-1;
        for(j=0;j < c ;j++){
            if(!visited[i][j].second) dfs(i,j,visited,grid,false);
        }

        // last column ---> RIGHT MOST COLUMN
        j = c-1;
        for(int i = 0;i < r;i++){
            if(!visited[i][j].second) dfs(i,j,visited,grid,false);
        }

        // result creation
        vector<vector<int>> result;

        for (int i=0;i< r ;i++){
            for(int j=0;j < c ;j++){
                if(visited[i][j].first && visited[i][j].second) result.push_back({i,j});
            }
        }

        return result;
        


    }
};