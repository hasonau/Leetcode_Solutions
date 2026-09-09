class Solution {
public:
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int dijkstra(vector<int>& dist, vector<int>& finalized,vector<vector<int>>& heights){
        
        int rows = heights.size();
        int columns = heights[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({heights[0][0], {0, 0}});
        dist[0] = heights[0][0];

        while(!pq.empty()){
            auto [distance,pos] = pq.top();
            auto [r,c] = pos;
            pq.pop();

            // row major 
            int u = (r*columns) + c;

            int parentNode = heights[r][c];

            if(distance > dist[u]) continue;

            finalized[u] = dist[u];


            for(auto [dr,dc] : directions){
                
                int row = r + dr;
                int col = c + dc;

                if(row < 0 || col < 0 || row >= rows || col >= columns) continue;

                int childNodeValue =  heights[row][col];

                int v = (row*columns) + col;
                int newDistance = max(distance , childNodeValue);

                if (newDistance < dist[v]) {
                    dist[v] = newDistance;
                    pq.push({newDistance, {row,col}});
                }
            }
        }

        return finalized[rows*columns-1];
    }


    int swimInWater(vector<vector<int>>& heights) {
        
        int rows= heights.size();
        int cols = heights[0].size();


        vector<int> finalized(rows*cols,-1);
        vector<int> dist(rows*cols, INT_MAX);

        return dijkstra(dist,finalized,heights);


    }
};