class Solution {
private:
    int find(int s, vector<int>& parent){
        if(parent[s] == -1){
            return s;
        }

        return find(parent[s], parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numEdges = edges.size();
        int n = numEdges + 1;

        vector<int> parent(n+1, -1);
        vector<int> ans;

        for(auto e: edges){
            int s = e[0];
            int d = e[1];

            int x = find(s, parent);
            int y = find(d, parent);

            if(x == y){
                ans = e;
            } else {
                parent[x] = y;
            }
        }

        return ans;
    }
};
