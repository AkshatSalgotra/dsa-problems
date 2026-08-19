class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        sort(res.begin(), res.end());
        int ans=0;
        int i=0;
        int m = res.size();
        int rowsDone = 0;
        while(i < m){
            int row = res[i][0];
            bool s1 = true, s2 = true, s3 = true;
            while(i < m && row == res[i][0]){
                if(res[i][1] == 2 || res[i][1] == 3) s1 = false;
                if(res[i][1] == 4 || res[i][1] == 5){
                    s1 = false;
                    s2 = false;
                }
                if(res[i][1] == 6 || res[i][1] == 7){
                    s2 = false;
                    s3 = false;
                }
                if(res[i][1] == 8 || res[i][1] == 9) s3 = false;
                i++;
            }
            if(s1 && s3) ans += 2;
            else if (s1 || s2 || s3) ans += 1;
            rowsDone++;
        }

        return ans += (n - rowsDone)*2;
    }
};