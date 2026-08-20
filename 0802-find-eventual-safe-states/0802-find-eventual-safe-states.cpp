class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj,vector<int>& outdegree,vector<int>& terminalNodes){


        queue<int> q;
        vector<int> result;
        for(auto terminal : terminalNodes){
            q.push(terminal);
            result.push_back(terminal);
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
        vector<int> terminalNodes;
        vector<vector<int>> adj(graph.size());
        vector<int> outdegree(graph.size(),0);

        // build reversed graph + collect terminal (0-outdegree) nodes
        for(auto [index,node] : std::views::enumerate(graph)){
            if(node.empty()){
                terminalNodes.push_back(index); 
                continue;
            } 
            outdegree[index] = node.size();
            // reverse Edges
            for(int i = 0; i < node.size();i++){
                adj[node[i]].push_back(index);
            }

        }
    
        return bfs(adj,outdegree,terminalNodes);


    }
};