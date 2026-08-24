class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto it = q.front();
                int r = it.first.first;
                int c = it.first.second;
                int d = it.second;
                dist[r][c] = d;
                vis[r][c] = true;
                q.pop();

                for(int k=0; k<4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]){
                        q.push({{nr, nc}, d+1});
                        vis[nr][nc] = true;
                    }
                }
            }
        }

        return dist;
    }
};