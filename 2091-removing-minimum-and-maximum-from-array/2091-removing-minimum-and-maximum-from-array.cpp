class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        pair<int, int> maxi = {INT_MIN, -1};
        pair<int, int> mini = {INT_MAX, -1};
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] > maxi.first){
                maxi.first = nums[i];
                maxi.second = i;
            }

            if(nums[i] < mini.first){
                mini.first = nums[i];
                mini.second = i;
            }
        }

        if(maxi.second > mini.second){
            return min({maxi.second+1, (mini.second + n-maxi.second + 1), n-mini.second});
        }

        else if (maxi.second < mini.second){
            return min({mini.second+1, (maxi.second + n-mini.second + 1), n-maxi.second});
        }

        else return maxi.second+1;
    }
};