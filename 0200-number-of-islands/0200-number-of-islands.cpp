class Solution {
public:
    int Rows;
    int Columns;
    void dfs(int i, int j,vector<vector<char>>& grid){
        // base case for OUT OF BOUND
        if(i < 0 || i >= Rows || j < 0 || j >= Columns || grid[i][j]=='0' || grid[i][j]=='2') return ;


        grid[i][j] = '2';
        // all four sides calls
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        // variables used in recursion
        Rows = grid.size();
        Columns = grid[0].size();
        // result variable
        int resultCount=0;

        for(int i = 0; i < Rows;i++){
            for(int j = 0; j < Columns ; j++){
                if( grid[i][j] == '1'){
                    // only increase the first time,all the recursion stuff is 
                    // to make this a complete island,but it still is one island,
                    resultCount++;
                    dfs(i,j,grid);
                }
            }
        }
        return resultCount;
    }
};