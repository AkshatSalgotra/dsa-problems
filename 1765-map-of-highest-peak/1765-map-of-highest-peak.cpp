class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        vector<vector<int>> vis(n, vector<int>(m, false));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        while(!q.empty()){
            auto it = q.front();
            int r = it.first.first;
            int c = it.first.second;
            int dist = it.second;
            ans[r][c] = dist;
            q.pop();

            for(int k=0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc]){
                    q.push({{nr, nc}, dist+1});
                    vis[nr][nc] = true;
                }
            }
        }

        return ans;
    }
};