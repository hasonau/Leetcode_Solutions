#include <deque>
#include <vector>



class Solution {
public:
    int zeroOneBFS(vector<vector<int>>& grid){
        
        int rows= grid.size();
        int cols = grid[0].size();

        std::deque<pair<int,pair<int,int>>> dq;

        std::vector<int> dist (rows*cols,INT_MAX);
        dq.push_front({0,{0,0}});
        dist[0] = 0;

        std::vector<pair<int,int>> directions = {
            {INT_MIN,INT_MAX}, // unused first value
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        while(!dq.empty()){

            auto [ cost, position ] = dq.front();
            dq.pop_front();
            auto [row,col] = position;


            // shortest minimum cost for sure
            // if(row == rows-1 && col == cols-1) return cost;

            int u = grid[row][col];

            auto [ free_row , free_col] = directions[u];

            int  no_cost_row = free_row + row;
            int  no_cost_col = free_col + col;

            if (no_cost_row >= 0 && no_cost_row < rows &&
                no_cost_col >= 0 && no_cost_col < cols) {
                int index = no_cost_row * cols + no_cost_col;

                if (cost < dist[index]) {
                    dq.push_front({cost, {no_cost_row, no_cost_col}});
                    dist[index] = cost;
                }
            }



            for(int i = 1 ; i < directions.size(); i++){
                
                if(i == u) continue;
                
                auto [dr , dc] = directions[i];
                int new_r = row + dr;
                int new_c = col + dc;

                if(new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols) continue;
                
                int newCost = cost + 1;
                int idx = new_r*cols + new_c;
                
                if((newCost) < dist[idx]){
                    dq.push_back({newCost,{new_r,new_c}});
                    dist[idx] = newCost;
                }
            }
        }
    return dist[rows*cols-1];
    }

    int minCost(vector<vector<int>>& grid) {
        
        return zeroOneBFS(grid);

    }
};