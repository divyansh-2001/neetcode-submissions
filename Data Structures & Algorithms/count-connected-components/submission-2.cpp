class Solution {
private:    
    void dfs(int edge, vector<vector<int>>& adj, unordered_set<int>& s){
        s.insert(edge);

        for(int i=0;i<adj[edge].size();i++){
            if(s.find(adj[edge][i]) == s.end()){
                dfs(adj[edge][i], adj, s);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        unordered_set<int> s;

        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(adj[i].size() == 0){
                ans++;
            }

            for(int j=0;j<adj[i].size();j++){
                if(s.find(adj[i][j]) != s.end()){
                    continue;
                }
                
                dfs(adj[i][j], adj, s);
                ans++;
            }
        }

        return ans;
    }
};
