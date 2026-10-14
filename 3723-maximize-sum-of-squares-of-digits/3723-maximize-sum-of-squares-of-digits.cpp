class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > (long long)num * 9) {
            return "";
        }
        
        string ans = "";
        ans.reserve(num); 
        
        for (int i = 0; i < num; ++i) {
            int d = min(9, sum);
            ans += (d + '0');
            sum -= d;
        }
        
        return ans;
    }
};