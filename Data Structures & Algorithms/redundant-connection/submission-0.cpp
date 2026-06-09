class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numEdges = edges.size();
        int n = numEdges + 1;

        vector<int> inedges(n+1);
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];

            inedges[a]++;
            inedges[b]++;
        }

        vector<int> ans;

        for(int i=numEdges-1;i>=0;i--){
            int a = edges[i][0];
            int b = edges[i][1];

            if(inedges[a] - 1 != 0 && inedges[b] - 1 != 0){
                ans.push_back(a);
                ans.push_back(b);
                break;
            }   
        }

        return ans;
    }
};
