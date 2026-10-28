class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int curr, vector<vector<vector<int>>> &dp){
        curr ^= grid[i][j];

        if(i == grid.size()-1 && j == grid[0].size()-1) return curr;

        if(dp[i][j][curr] != -1) return dp[i][j][curr];

        int c1 = INT_MAX, c2 = INT_MAX;
        if(i < grid.size()-1) c1 = solve(grid, i+1, j, curr, dp);
        if(j < grid[0].size()-1) c2 = solve(grid, i, j+1, curr, dp);

        int mini = min(c1, c2);
        return dp[i][j][curr] = mini;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(1024, -1)));
    
        return solve(grid, 0, 0, 0, dp);

    }
};