class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj,vector<int>& outdegree){


        queue<int> q;
        vector<int> result;
        for(auto [index,value] : std::views::enumerate(outdegree)){
            if(value == 0){
                q.push(index);
                result.push_back(index);
            }
        }


        while(!q.empty()){

            int u = q.front();
            q.pop();

            for(int v : adj[u]){
                outdegree[v]--;
                if(outdegree[v] == 0){
                    q.push(v);
                    result.push_back(v);
                } 
            }
        }
        sort(result.begin(),result.end());
        return result; 
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<vector<int>> adj(graph.size());
        vector<int> outdegree(graph.size(),0);

        for(auto [index,node] : std::views::enumerate(graph)){
            outdegree[index] = node.size();
            // reverse Edges
            for(int i = 0; i < node.size();i++){
                adj[node[i]].push_back(index);
            }

        }
    
        return bfs(adj,outdegree);


    }
};