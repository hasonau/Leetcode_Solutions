class Solution {
public:
    vector<int> bfs( unordered_map<int,vector<int>>& adj,vector<int>& outdegree,vector<int>& terminalNodes){


        queue<int> q;
        vector<int> result;
        for(auto terminal : terminalNodes){
            q.push(terminal);
            result.push_back(terminal);
        }


        while(!q.empty()){
            int counter =0;
            int q_size = q.size();

            while(counter < q_size){
                int u = q.front();
                q.pop();

                for(int v : adj[u]){
                    outdegree[v]--;
                    if(outdegree[v] == 0){
                        q.push(v);
                        result.push_back(v);
                    } 
                }
                counter++;
            }
        }
        sort(result.begin(),result.end());
        return result; 
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> terminalNodes;
        unordered_map<int,vector<int>> adj;
        vector<int> outdegree(graph.size(),0);

        // adj and terminalNodes noted
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