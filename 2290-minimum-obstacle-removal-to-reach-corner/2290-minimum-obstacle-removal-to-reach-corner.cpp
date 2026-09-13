
#include <deque>
#include <vector>



class Solution {
public:
    int zeroOneBFS(vector<vector<int>>& grid){
        
        int rows= grid.size();
        int cols = grid[0].size();

        std::deque<pair<int,pair<int,int>>> dq;

        std::vector<int> dist (rows*cols,INT_MAX);
        dq.push_front({grid[0][0],{0,0}});

        if(grid[0][0]) dist[0] = 1;
        else dist[0] = 0;

        std::vector<pair<int,int>> directions = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        while(!dq.empty()){

            auto [ cost, position ] = dq.front();
            dq.pop_front();
            auto [row,col] = position;


            for(int i = 0 ; i < directions.size(); i++){
                
                // if(i == u) continue;
                
                auto [dr , dc] = directions[i];
                int new_r = row + dr;
                int new_c = col + dc;

                if(new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols) continue;
                
                int idx = new_r*cols + new_c;
                int newCost = cost;
                if(grid[new_r][new_c]) newCost+=1;
                
                if(newCost >= dist[idx]) continue;

                if(grid[new_r][new_c] == 1){
                    dq.push_back({newCost,{new_r,new_c}});
                } 
                else{
                    dq.push_front({newCost,{new_r,new_c}});
                }
                dist[idx] = newCost;
            }
        }
    return dist[rows*cols-1];
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        
        return zeroOneBFS(grid);

    }
};