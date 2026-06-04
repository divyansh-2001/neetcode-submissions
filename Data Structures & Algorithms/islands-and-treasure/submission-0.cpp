class Solution {
private:
    bool isValid(int dx, int dy, int m, int n){
        return dx >= 0 && dx < m && dy >= 0 && dy < n;
    }

    int arr[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == -1 || grid[i][j] == INT_MAX){
                    continue;
                }

                q.push({i,j});
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int dx = top.first + arr[i][0];
                int dy = top.second + arr[i][1];

                if(!isValid(dx, dy, m,n) || grid[dx][dy]!=INT_MAX){
                    continue;
                }

                grid[dx][dy] = grid[top.first][top.second] + 1;
                q.push({dx, dy});
            }
        }
    }
};
