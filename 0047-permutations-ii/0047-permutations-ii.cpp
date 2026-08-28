class Solution {
public:

    void solve(int idx, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        if(idx == n){
            ans.push_back({nums});
            return;
        }

        unordered_set<int> seen;
        for(int i=idx; i<n; i++){
            if(seen.count(nums[i])) continue;

            seen.insert(nums[i]);
            swap(nums[i], nums[idx]);
            solve(idx+1, nums, ans);

            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};