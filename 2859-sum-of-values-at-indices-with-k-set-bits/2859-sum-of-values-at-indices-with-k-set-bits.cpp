class Solution {
public:
    int cntSet(int num){
        int cnt=0;
        while(num){
            num = num & num-1;
            cnt++;
        }

        return cnt;
    }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;

        for(int i=0; i<nums.size(); i++){
            if(cntSet(i) == k) sum += nums[i];
        }

        return sum;
    }
};