class Solution {
public:
   vector<pair<int,int>> directions = {
    {-1, 0},  // up
    {1, 0},   // down
    {0, -1},  // left
    {0, 1}    // right
    };

    void dfs(vector<vector<int>>& image, int i, int j, int color,int originalColor){
        int r = image.size();
        int c = image[0].size();
        
        image[i][j] = color;

        for(auto [x,y] : directions){

            int new_i = i + x ;
            int new_j = j + y ;

            if(new_i < 0 || new_j < 0 || new_i >= r || new_j >= c || originalColor != image[new_i][new_j]) continue;

            // image[new_i][new_j] = color;

            // now process that cell
            dfs(image,new_i,new_j,color,originalColor);
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int originalColor = image[sr][sc];

        // early exit
        if(originalColor == color) return image;

        
        // modify image
        dfs(image,sr,sc,color,originalColor);

        return image;


       
    }
};