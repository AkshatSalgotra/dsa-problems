class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int k = target - nums[i];
            int l = i+1, r = n-1;
            int sum;
            while(l < r){
                sum = nums[l] + nums[r];
                if(diff > abs(sum-k)){
                    ans = sum + nums[i];
                    diff = abs(sum-k);
                }
                
                if(sum > k) r--;
                else l++;
            }
        }

        return ans;
    }
};