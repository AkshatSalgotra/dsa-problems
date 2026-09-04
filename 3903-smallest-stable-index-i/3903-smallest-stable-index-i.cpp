class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];

        int mini = INT_MAX;
        int ans = -1;
        for(int i=1; i<n; i++){
            pref[i] = max(pref[i-1], nums[i]);
        }

        for(int i = n-1; i>=0; i--){
            mini = min(mini, nums[i]);
            if(pref[i]-mini <= k) ans = i;
        }

        return ans;
    }
};