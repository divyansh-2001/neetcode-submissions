class Solution {
private:
    bool isValid(int x, int y, int m, int n){
        return x >=0 && x < m && y >= 0 && y < n;
    }

    int arr[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // if(board[i][j] == 'X'){
                //     vis[i][j] = 1;
                // }

                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O'){
                        // vis[i][j] = 1;
                        board[i][j] = 'Y';
                        q.push({i,j});
                    }
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int dx = top.first + arr[i][0];
                int dy = top.second + arr[i][1];

                if(!isValid(dx, dy, m, n) || board[dx][dy] == 'X'){
                    continue;
                }

                // vis[dx][dy] = 1;
                board[dx][dy] = 'Y';
                q.push({dx, dy});
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
