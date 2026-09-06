class Solution {
public:
    void bfs(int k,vector<int>& visited, vector<int>& finalized,vector<vector<pair<int,int>>>& adj){

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0,k});

        int countUnique = 1;
        visited[k] = 0;

        while(!pq.empty()){
            auto [distance,u] = pq.top();
            pq.pop();

            if(distance > visited[u]) continue;

            finalized[u] = visited[u];


            for(auto [v,weight] : adj[u]){
                int newDistance = distance + weight;

                if (newDistance < visited[v]) {
                    visited[v] = newDistance;
                    pq.push({newDistance, v});
                }
            }
        }
        return;
    }




    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto time :  times) {
            int src = time[0];
            int trgt = time[1];
            int weight = time[2];

            adj[src].push_back({trgt,weight});
        }

        vector<int> finalized(n+1,-1);
        vector<int> visited(n+1, INT_MAX);

        bfs(k,visited,finalized,adj);

        int count = 0;
        int maxResult = INT_MIN;
        for(int i = 1; i <= n ;i++){
            if(finalized[i]!= -1) count++;
            maxResult = max(finalized[i],maxResult);
        }

        if(count < n) return -1;

        return maxResult;

    }
};