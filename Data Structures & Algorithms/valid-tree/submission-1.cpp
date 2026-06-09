class Solution {
private:
    bool dfs(vector<vector<int>>& adj, int i, int parent, unordered_set<int>& s){
        for(int j=0;j<adj[i].size();j++){
            int edge = adj[i][j];

            if(edge == parent){
                continue;
            }

            if(s.find(edge) != s.end()){
                return false;
            }

            s.insert(edge);
            bool tempAns = dfs(adj, edge, i, s);
            if(!tempAns){
                return false;
            }
        }

        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        unordered_set<int> s;

        // s.insert(0);
        // dfs(adj, 0, -1, s);
        
        int count = 0;

        for(int i=0;i<n;i++){
            if(s.find(i) != s.end()){
                continue;
            }
            
            count++;
            s.insert(i);
            bool tempAns = dfs(adj, i, -1, s);
            if(!tempAns){
                return tempAns;
            }
        }
        
        return count == 1;
    }
};
