class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> hash;

        for(int i=0; i<n; i++){
            hash.insert(nums[i]);
        }

        int num = k;
        while(1){
            if(hash.find(num) == hash.end()) return num;
            num += k;
        }

        return -1;
    }
};