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
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& m){
        vector<Node*> neighbors;
        Node* newNode = new Node(node->val, neighbors);
        
        // newNode -> neighbors = neighbors;

        m[node] = newNode;

        for(auto n: node->neighbors){
            if(m.find(n) == m.end()){
                Node* newN = dfs(n, m);
                newNode -> neighbors.push_back(newN);
            } else {
                newNode -> neighbors.push_back(m[n]);
            }
        }

        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }

        unordered_map<Node*, Node*> m;
        dfs(node, m);

        return m[node];
    }
};
