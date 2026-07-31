class Solution {
public:
    void recursiveBFS(int u , unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        if(visited[u]) return ;

        queue<int>q;
        q.push(u);
        visited[u]= true;
        
        while(!q.empty()){
            u = q.front();
            q.pop();

            for(int& v : adj[u]){
                if(!visited[v]) recursiveBFS(v,adj,visited);
            }
        }
        return ;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int r= isConnected.size();
        int c= isConnected[0].size();
        int count = 0;
        unordered_map<int,vector<int>> adj;

        for(int i = 0 ;i < r ;i++){
            for(int j = 0; j < c ; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(r,false);

        for(int i=0;i< r;i++){
            if(!visited[i]) {count++; recursiveBFS(i,adj,visited);}
        }
        return count;
    }
};