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

    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<int> parent(n); 

        // Individual nodes are parent of themselves
        for (int i = 0 ;i < n; i++){
            parent[i] = i;
        }

        int redundantConnection= 0;

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(unionF(u,v,parent)) redundantConnection++;
        }

        unordered_set<int> components;

        for (int i = 0 ;i < n; i++){
            components.insert(findRep(i,parent));
        }

        int componentsCount = components.size();
        cout<<"componentsCount = "<<componentsCount<<endl;
        if(componentsCount == 1) return 0;

        // 1 component can be made
        if(componentsCount - redundantConnection <= 1){
            if(componentsCount - redundantConnection == 1) return redundantConnection;
            return componentsCount - 1;
        }
        else return -1;
    }

};