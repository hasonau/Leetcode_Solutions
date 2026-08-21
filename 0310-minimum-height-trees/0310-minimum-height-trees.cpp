class Solution {
public:
    vector<int> bfs(vector<int>& degree,vector<vector<int>>& adj){
        
        queue<int>q;
        int count = 0;

        for(auto [index,val] : std::views::enumerate(degree)){
            if(val == 1){
                q.push(index);
                degree[index]--;
                count++;
            } 
        }
        int popped =0;
        while(!q.empty()){
            int counter = 0;
            int q_size = q.size();

            while(counter < q_size){

                int u = q.front();
                q.pop();
                popped++;

                for(int v : adj[u]){
                    degree[v]--;
                    if(degree[v] == 1) {
                        q.push(v);
                    }
                }
            counter++;
            }
            if(adj.size() - popped == 2 || adj.size() - popped == 1) break;
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;


    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(edges.size() == 0) return {0};
        if(edges.size() == 1) return {edges[0][0],edges[0][1]};
        
        vector<int>degree(n);
        vector<vector<int>> adj(n);

        for(auto [index,edge] : std::views::enumerate(edges)){

                degree[edge[0]]++;
                degree[edge[1]]++;

                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
        }

        return bfs(degree,adj);
    }
};