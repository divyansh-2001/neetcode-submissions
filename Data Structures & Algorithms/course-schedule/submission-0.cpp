class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inedges(numCourses, 0);
        queue<int> q;
        int count = 0;

        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            inedges[a]++;
        }

        for(int i=0;i<numCourses;i++){
            if(inedges[i] == 0){
                q.push(i);
            }
        }

        if(q.empty()){
            return false;
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            count++;

            for(int i=0;i<adj[top].size();i++){
                int a = adj[top][i];
                if(--inedges[a] == 0){
                    q.push(a);
                }
            }
        }

        return count == numCourses;
    }
};
