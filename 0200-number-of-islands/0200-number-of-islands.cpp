class Solution {
public:
    void recursive(int i,int j,vector<vector<char>>& grid){
        int r =grid.size();
        int c =grid[0].size();

        if(i < 0 || i >=r || j < 0 || j >= c || grid[i][j]!='1') return;
        // setting grid[i][j] to visited,meaning water here

        grid[i][j]='0';

        vector<pair<int,int>> directions = {
            {-1,0}, // up
            {1,0},  // down
            {0,1},  // right
            {0,-1}  // left
        };

        for(pair<int,int>& direction :directions){
            recursive(i+direction.first,j+direction.second,grid);
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int r =grid.size();
        int c =grid[0].size();
        int count =0;
        for(int i=0;i < r;i++){
            for(int j=0;j<c;j++){
                if( grid[i][j]== '1'){
                    recursive(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};