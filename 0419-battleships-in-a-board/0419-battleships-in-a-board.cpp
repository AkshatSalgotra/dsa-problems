class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int cnt = 0;
        
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    q.push({i, j});
                    vis[i][j] = true;
                    cnt++;

                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();

                        for(int i=0; i<4; i++){
                            int nr = r + dr[i];
                            int nc = c + dc[i];

                            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'X'){
                                q.push({nr, nc});
                                vis[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};