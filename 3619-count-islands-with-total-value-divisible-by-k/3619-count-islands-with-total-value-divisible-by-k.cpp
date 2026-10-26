class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && vis[i][j] == false) {
                    long long currSum = grid[i][j];
                    queue<pair<int, int>> q;
                    vis[i][j] = true;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto it = q.front();
                        q.pop();
                        for (int z = 0; z < 4; z++) {
                            int nr = it.first + dr[z];
                            int nc = it.second + dc[z];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                !vis[nr][nc] && grid[nr][nc] > 0) {
                                vis[nr][nc] = true;
                                currSum += grid[nr][nc];
                                q.push({nr, nc});
                            }
                        }
                    }
                    if (currSum % k == 0)
                        islands++;
                }
            }
        }

        return islands;
    }
};