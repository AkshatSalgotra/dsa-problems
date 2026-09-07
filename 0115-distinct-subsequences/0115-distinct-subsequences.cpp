class Solution {
public:
    int solve(string s, string t, int i, int j, vector<vector<int>>& dp){
        int n1 = s.length();
        int n2 = t.length();

        if(j == n2) return 1;
        if(i == n1) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int ways = 0;
        if(s[i] == t[j]) ways = solve(s, t, i+1, j+1, dp) + solve(s, t, i+1, j, dp);
        else  ways = solve(s, t, i+1, j, dp);

        return dp[i][j] = ways;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return solve(s, t, 0, 0, dp);
    }
};