class Solution {
public:
    bool bipartiteBFS(int u ,vector<vector<int>>& adj,vector<pair<bool,char>>& visited){

        queue<int> q;
        visited[u].first = true;
        visited[u].second = 'R';         // Red color
        q.push(u);

        // bool Color = 0;         // Red color  == false

        while(!q.empty()){

            // inner loop helpers
            int counter =0;
            int q_size = q.size();

            // char groups[2] = {'R','B'};

            while(counter < q_size){

                int u = q.front();
                q.pop();

                for(int v : adj[u]){

                    // parent case,skipped
                    if(v == u) continue;

                    // if already visited,check if it's color is same as of the current color
                    if(visited[v].first){
                        if(visited[v].second == visited[u].second) return false;
                        // no need to push it again to queue,the already visited case
                        continue;
                    }

                    // otherwise process it now
                    visited[v].first = true;
                    visited[v].second = visited[u].second == 'R' ? 'B' : 'R';
                    q.push(v);
                }
                counter++;
            }
        }
        return true; 
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();

        // N means not explored,but it's just value,it won't be used later
        vector<pair<bool,char>> visited(V,{false,'N'}); 


        for(int i = 0 ;i < V ; i++){
            if(!visited[i].first && !bipartiteBFS(i,adj,visited)) return false;
        }
        return true;
    }
};