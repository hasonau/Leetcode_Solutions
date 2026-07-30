class Solution {
public:
    unordered_set<int> s;
    void recursiveDFS(int u,unordered_map<int,vector<int>>& adj){

        s.insert(u);
        for(int& v : adj[u]){
            if(v && (s.find(v) == s.end())){
                recursiveDFS(v,adj);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int r = isConnected.size();
        int c = isConnected[0].size();
        // always remember to initialize ,otherwise random results keep popping
        int provincesCount=0;
        unordered_map<int,vector<int>> adj(r);

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    // avoiding the self edge,for better dfs traversal later on
                    if(i!=j){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }

        for(int i = 0; i < r; i++) {
            if(s.find(i) == s.end()) {
                provincesCount++;
                recursiveDFS(i, adj);
            }
        }
        return provincesCount;
    }
};