class Solution {
public:
    double dfs(string start,string end,unordered_map<string,vector<string>>& adj,unordered_set<string>& visited,unordered_map<string,double>& equationsMap){

    double result = -1.0;
    for(auto v : adj.contains(start) ? adj[start] : vector<string>{}){

        string s = start + "/" + v;

        // do not process a link already in visited
        if(visited.contains(s)) continue;

        // base case
        if(v == end) return equationsMap[s];

        // now process it 
        visited.insert(s);
        double currentResult = dfs(v,end,adj,visited,equationsMap);
        if(currentResult!=-1) result = equationsMap[s] * currentResult;
    }
    return result;
}


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string,double> equationsMap;

        for(auto [index, query] : equations | std::views::enumerate){
            string s = query[0] + "/" + query[1];
            string reverseS = query[1] + "/" + query[0];
            

            equationsMap[s] = values[index];
            equationsMap[reverseS] = 1.0 / values[index] ;
        }

        unordered_map<string,vector<string>> adj;

        for(auto equation : equations){
            adj[equation[0]].push_back(equation[1]);
            adj[equation[1]].push_back(equation[0]);
        }

        vector<double> result(queries.size(), -1.0);

        for(auto [index,query] : queries | std::views::enumerate){
            unordered_set<string> visited;
            // explicit same-variable check: if the variable equals itself and exists in adj , answer is 1
            if(query[0] == query[1] && adj.contains(query[0])){
                    result[index] = 1.0;
                    continue;
            }
            result[index] = dfs(query[0],query[1],adj,visited,equationsMap);
        }
        return result;
    }
};