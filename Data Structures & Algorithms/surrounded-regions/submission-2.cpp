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

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O'){
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

                if(!isValid(dx, dy, m, n) || board[dx][dy] == 'X' || board[dx][dy] == 'Y'){
                    continue;
                }

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
