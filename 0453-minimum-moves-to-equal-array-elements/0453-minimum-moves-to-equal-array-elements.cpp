class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());

        int cnt = 0;
        for(int num : nums) cnt += abs(mini - num);

        return cnt;
    }
};