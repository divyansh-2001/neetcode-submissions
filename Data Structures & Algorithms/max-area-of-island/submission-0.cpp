class Solution {
private:
    bool isValid(int x, int y, int m, int n){
        return x >=0 && x < m && y >= 0 && y < n;
    }

    int arr[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited){
        visited[x][y] = true;

        int ans = 1;

        for(int i=0;i<4;i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];

            if(isValid(dx, dy, grid.size(), grid[0].size()) && !visited[dx][dy] && grid[dx][dy] == 1){
                ans += dfs(grid, dx, dy, visited);
            }
        }

        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(), false));
        int ans = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j] || grid[i][j] == 0){
                    continue;
                }

                int temp = dfs(grid, i, j, visited);
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};
