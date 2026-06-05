class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> adj(numCourses);
        vector<int> inedges(numCourses, 0);
        vector<int> ans;
        queue<int> q;

        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            inedges[a]++;
        }

        for(int i=0;i<numCourses;i++){
            if(inedges[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        if(q.empty()){
            return {};
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int i=0;i<adj[top].size();i++){
                int a = adj[top][i];
                if(--inedges[a] == 0){
                    q.push(a);
                    ans.push_back(a);
                }
            }
        }

        vector<int> temp;

        return ans.size() == numCourses ? ans:temp;
    }
};
