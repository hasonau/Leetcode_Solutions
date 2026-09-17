class Solution {
public:
    int findRep(int u,vector<int>& parent){
        if(u == parent[u]) return u;

        return findRep(parent[u],parent);
    }


    bool unionF(int u,int v,vector<int>& parent){
        
        int u_parent = findRep(u,parent);
        int v_parent = findRep(v,parent);

        // redundant connection found
        if(u_parent == v_parent) return true;

        if(u_parent != v_parent){
            parent[v_parent] = u_parent; 
        }
        
        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(1001); 

        // Individual nodes are parent of themselves
        for (int i = 1 ;i <= 1000; i++){
            parent[i] = i;
        }

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(unionF(u,v,parent)) return edge;
        }

        return {};
    }
};