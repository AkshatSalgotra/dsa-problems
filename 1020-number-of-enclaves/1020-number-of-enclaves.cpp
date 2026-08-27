class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for(int j=0; j<m; j++){
            if(board[0][j] == 1){
                q.push({0, j});
                vis[0][j] = true;
            }

            if(board[n-1][j] == 1){
                q.push({n-1, j});
                vis[n-1][j] = true;
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][0] == 1){
                q.push({i, 0});
                vis[i][0] = true;
            }

            if(board[i][m-1] == 1){
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
                    if(board[nr][nc] == 1){
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                    } 
                }
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};