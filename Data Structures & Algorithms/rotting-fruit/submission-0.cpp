class Solution {
private:
    bool isValid(int x, int y, int m, int n){
        return x >=0 && x < m && y >= 0 && y < n;
    }

    int arr[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }   

        q.push({-1, -1});
        int t = 1;
        bool consecBreak = false;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            if(top.first == -1){
                if(consecBreak){
                    break;
                }

                consecBreak = true;
                q.push({-1, -1});
                t++;

                continue;
            }

            consecBreak = false;

            for(int i=0;i<4;i++){
                int dx = top.first + arr[i][0];
                int dy = top.second + arr[i][1];

                if(!isValid(dx, dy, m, n) || grid[dx][dy] != 1){
                    continue;
                }

                grid[dx][dy] = 2;
                q.push({dx, dy});
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return t-2;
    }
};
