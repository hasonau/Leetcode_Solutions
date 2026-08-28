/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* bfs(Node* node){

        vector<Node*> visited(101,nullptr);
        queue<Node*>q;
        q.push(node);
        visited[node->val] = new Node(node->val);  // original to clone

        while(!q.empty()){
            Node* originalNode = q.front();
            Node* cloneNode = visited[originalNode->val];

            q.pop();

            for (Node* originalNeighbor : originalNode->neighbors) {
                                
                if(visited[originalNeighbor->val]) {
                    
                    Node* cloneNeighbor = visited[originalNeighbor->val];
                    cloneNode->neighbors.push_back(cloneNeighbor);
                    // cloneNeighbor->neighbors.push_back(cloneNode);
                    continue;
                }

                
                Node* cloneNeighbor = new Node(originalNeighbor->val);

                // undirected edges
                cloneNode->neighbors.push_back(cloneNeighbor);
                // mapping original to clone
                visited[originalNeighbor->val] = cloneNeighbor;
                // for further exploration
                q.push(originalNeighbor);
            }

        }
        return visited[node->val];
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(node->neighbors.empty()) return new Node(node->val);

        return bfs(node);
    }
};