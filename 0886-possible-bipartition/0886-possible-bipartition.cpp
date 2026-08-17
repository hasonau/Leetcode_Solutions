class Solution {
public:
    bool dfsBipartiteCheck(int u,vector<vector<int>>& adj, vector<int>& visited){
        cout<<"ENTER DFS"<<endl;
        cout<<"u = "<<u<<endl;        
        cout<<"visited[u] = "<<visited[u]<<endl;        
    

        for(int v : adj[u]){
            if(v == u) continue;
            // now check if already set,and set same as the one we holding,the parent,now,then it can't be bipartite return fasle
            if(visited[v] == visited[u]) return false;

           if(visited[v]==0){
             // not set already,so set it and move on
            if(visited[u]==1) visited[v] = 2;
            else visited[v] = 1;
            
            // now call it 
            if(!dfsBipartiteCheck(v,adj,visited)) return false;
           }
        }

        return true;
    }


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);

        for(auto dislike : dislikes){
            int u = dislike[0];
            int v = dislike[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>visited(n+1,0);

        for(int i= 1; i <= n ; i++){
            if(visited[i]==0) visited[i] = 1;
            if(!dfsBipartiteCheck(i,adj,visited)) return false;
        }


        return true;
    }
};