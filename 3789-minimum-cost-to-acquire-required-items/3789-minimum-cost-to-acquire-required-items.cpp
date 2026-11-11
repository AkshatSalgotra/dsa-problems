class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        if(need1 > need2){
            if(costBoth < cost1 + cost2){
                ans += (long long)costBoth * need2 + (long long)min(costBoth, cost1) * (need1-need2);
            } else {
                ans += (long long)need1 * cost1 + (long long)need2 * cost2;
            }
        } else {
            if(costBoth < cost1 + cost2){
                ans += (long long)costBoth * need1 + (long long)min(costBoth, cost2) * (need2-need1);
            } else {
                ans += (long long)need1 * cost1 + (long long)need2 * cost2;
            }
        }

        return ans;
    }
};