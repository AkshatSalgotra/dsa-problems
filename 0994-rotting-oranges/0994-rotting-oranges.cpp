class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int freshCnt=0;
        queue<pair<int, int>>q;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) freshCnt++;
            }
        }
        if(freshCnt == 0) return 0;

        int time = 0;
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        while(!q.empty()){
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            int size = q.size();

            for(int i=0; i<size; i++){
                auto it = q.front();
                vis[it.first][it.second] = true;
                q.pop();
                for(int k=0; k < 4; k++){
                    int nr = it.first + dr[k];
                    int nc = it.second + dc[k];

                    if(nr >= 0 && nr < r && nc >= 0 && nc < c && !vis[nr][nc] && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                        freshCnt--;
                    }
                }
            }
            time++;
        }

        return freshCnt == 0 ? time-1 : -1;
    }
};