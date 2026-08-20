class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long maxi1 = LLONG_MIN;
        long long maxi2 = LLONG_MIN;
        

        for(int i=0; i<nums.size(); i++){
            if(abs(nums[i]) > maxi1){
                maxi2 = maxi1;
                maxi1 = abs(nums[i]);
            } else if(abs(nums[i]) > maxi2) maxi2 = abs(nums[i]);
        }

        return maxi1*maxi2*1e5;
    }
};