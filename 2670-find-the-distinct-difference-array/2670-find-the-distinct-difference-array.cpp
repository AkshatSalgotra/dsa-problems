class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        set<int> prefSet, suffSet;
        vector<int> pref(n);

        for(int i=0; i<n; i++){
            prefSet.insert(nums[i]);
            pref[i] = prefSet.size();
        }

        for(int i=n-1; i>=0; i--){
            pref[i] = pref[i] - suffSet.size();
            suffSet.insert(nums[i]); 
        }

        return pref;
    }
};