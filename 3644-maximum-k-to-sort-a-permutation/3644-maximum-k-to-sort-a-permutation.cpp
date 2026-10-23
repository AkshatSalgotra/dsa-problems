class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        bool isSort = true;
        int k = -1;

        for(int i=0; i<n; i++){
            if(nums[i] != i){
                k &= nums[i];
                isSort = false;
            }
        }

        if(isSort) return 0;

        return k;
    }
};