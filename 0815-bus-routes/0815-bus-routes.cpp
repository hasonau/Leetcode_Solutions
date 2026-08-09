class Solution {
public:
    // int T;
    int bfs(int source,int target,unordered_map<int,vector<int>>& stopToRoutes,unordered_set<int>& visited,vector<vector<int>>& routes){
        if (source == target) return 0;
        queue<int>q;

        for (int route : stopToRoutes[source]) {
            q.push(route);
            visited.insert(route);
        }

        int level = 1;
        while(!q.empty()){

            int q_size = q.size();
            int counter = 0;

            while(counter < q_size){
                int u = q.front();
                q.pop();
                // if(visited.find(target)!=visited.end()) return level;

                for(int stop : routes[u]){
                    if(stop == target) return level;
                    for (int v : stopToRoutes[stop]) {
                        // v = another route sharing this stop
                        if(visited.find(v)!=visited.end()) continue;

                        q.push(v);
                        visited.insert(v);
                    }
                }
                counter++;
            }
            level++;
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // T = target;
        unordered_map<int,vector<int>> stopToRoutes;
        // stops are unique,as per question
        unordered_set<int> visited;


        for (int route = 0; route < routes.size(); route++)
            for (int stop : routes[route])
                stopToRoutes[stop].push_back(route);


        return bfs(source,target,stopToRoutes,visited,routes);
    }
};