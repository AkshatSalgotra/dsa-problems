class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for(int j=0; j<m; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                vis[0][j] = true;
            }

            if(board[n-1][j] == 'O'){
                q.push({n-1, j});
                vis[n-1][j] = true;
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                vis[i][0] = true;
            }

            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
                vis[i][m-1] = true;
            }
        }

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            for(int k=0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >=0 && nr < n && nc >=0 && nc < m && !vis[nr][nc]){
                    if(board[nr][nc] == 'O'){
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                    } 
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};