class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int prev1 = 0;
        int prev2 = 1e9;
        int prev3 = 1e9;

        for(int i=1; i <= n; i++){
            int currCost = min({prev1+costs[i-1]+1, prev2+costs[i-1]+4, prev3+costs[i-1]+9});

            prev3 = prev2;
            prev2 = prev1;
            prev1 = currCost;
        }

        return prev1;
    }
};