class Solution {
public:
    int digSum(int num){
        int sum=0;

        while(num){
            sum += num%10;
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dig(n);

        for(int i=0; i<n; i++){
            dig[i] = {nums[i], i};
        }

        sort(dig.begin(), dig.end(), [&](const auto a, const auto b){
            int sumA = digSum(a.first);
            int sumB = digSum(b.first);

            if(sumA == sumB) return a.first < b.first;
            return sumA < sumB;
        });

        int swaps = 0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(vis[i] || dig[i].second == i) continue;

            int sz = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = dig[j].second;
                sz++;
            }

            if(sz > 0) swaps += sz-1;
        }

        return swaps;
    }
};