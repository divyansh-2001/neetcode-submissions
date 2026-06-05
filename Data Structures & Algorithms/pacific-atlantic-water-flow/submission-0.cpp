class Solution {
private:
    bool isValid(int x, int y, int m, int n){
        return x >=0 && x < m && y >= 0 && y < n;
    }

    int arr[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    
    void bfs(vector<vector<int>>& heights, vector<vector<int>>& vis, queue<pair<int,int>>& q){
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int dx = top.first + arr[i][0];
                int dy = top.second + arr[i][1];

                if(!isValid(dx, dy, vis.size(), vis[0].size()) || heights[dx][dy] < heights[top.first][top.second] || vis[dx][dy] == 1){
                    continue;
                }

                vis[dx][dy] = 1;
                q.push({dx, dy});
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, -1));
        vector<vector<int>> atlantic(m, vector<int>(n, -1));

        queue<pair<int,int>> q1, q2;

        for(int i=0;i<n;i++){
            q1.push({0, i});
            pacific[0][i] = 1;

            q2.push({m-1, i});
            atlantic[m-1][i] = 1;
        }

        for(int i=0;i<m;i++){
            q1.push({i, 0});
            pacific[i][0] = 1;

            q2.push({i, n-1});
            atlantic[i][n-1] = 1;
        }

        bfs(heights, pacific, q1);
        bfs(heights, atlantic, q2);

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
