class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i == n-1 && j == m-1) return 1;
        if(i < 0 || i > n-1 || j < 0 || j > m-1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int r1 = i, c1 = j+1;
        bool right = true;
        while(r1 < n && c1 < m && grid[r1][c1] == 1){
            if(right){
                r1++;
            } else {
                c1++;
            }
            right = !right;
        }

        int r2 = i+1, c2 = j;
        bool down = true;
        while(r2 < n && c2 < m && grid[r2][c2] == 1){
            if(!down){
                r2++;
            } else {
                c2++;
            }
            down = !down;
        }

        long long ans = 0;
        if(r1 < n && c1 < m) ans += solve(grid, r1, c1, dp)%(int)(1e9+7);
        if(r2 < n && c2 < m) ans += solve(grid, r2, c2, dp)%(int)(1e9+7);

        return dp[i][j] = ans%(int)(1e9+7);
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, 0, 0, dp);
    }
};