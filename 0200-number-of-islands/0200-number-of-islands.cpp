
class Solution {
public:
    void recursiveDFS(int i, int j,vector<vector<char>>& isConnected){
        int r = isConnected.size();
        int c = isConnected[0].size();

        if(i < 0 || i >= r || j < 0 || j >= c || isConnected[i][j]!= '1') return ;

        isConnected[i][j] = '0';
        vector<pair<int,int>> directions = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };
        for (auto direction : directions){
            int first = direction.first;
            int second = direction.second;
            // cout<<"calling recursive "<<endl;
            recursiveDFS(i + first,j + second,isConnected);
        }

        return ;
    }
    int numIslands(vector<vector<char>>& isConnected) {
        int r = isConnected.size();
        int c = isConnected[0].size();
        // always remember to initialize ,otherwise random results keep popping
        int provincesCount=0;
        for(int i=0;i < r ; i++ ){
            for(int j=0; j < c ; j++ ){
                if(isConnected[i][j]!= '0'){
                    provincesCount++;
                    recursiveDFS(i,j,isConnected);
                }
            }
        }
        return provincesCount;
    }
};