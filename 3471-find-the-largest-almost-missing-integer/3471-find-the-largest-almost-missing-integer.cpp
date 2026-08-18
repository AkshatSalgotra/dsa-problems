class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++) freq[nums[i]]++;

        if(k == 1){
            int maxi = -1;
            for(int i=0; i<n; i++){
                if(freq[nums[i]] == 1) maxi = max(maxi, nums[i]);
            }
            return maxi;
        }

        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }

        if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1) return max(nums[0], nums[n-1]);
        if(freq[nums[0]] == 1) return nums[0];
        if(freq[nums[n-1]] == 1) return nums[n-1];
        return -1;
    }
};