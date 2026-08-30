class Solution {
public:
    int kahn_algo(vector<vector<int>>& adj,vector<int>& indegrees){

        queue<int> q;
        vector<int> result;

        for(auto [index,indegree] : std::views::enumerate(indegrees)){
            if(indegree == 0) {
                q.push(index);
                result.push_back(index);
            }
        }

        while(!q.empty()){
            int level_counter = 0;
            int q_size = q.size();

            while(level_counter < q_size){
                int u = q.front();
                q.pop();

                for(int v : adj[u]){
                    indegrees[v]--;
                    if(indegrees[v] == 0) {
                        q.push(v);
                        result.push_back(v);
                    }
                }
            level_counter++;    
            }
        }
        int result_size = result.size();
        return result.size();
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);

        for(auto p : prerequisites){
            int u = p[1];
            int v = p[0];

            adj[u].push_back(v);
            indegrees[v]++;
        }

        return kahn_algo(adj,indegrees) == numCourses ? true : false ;
    }
};