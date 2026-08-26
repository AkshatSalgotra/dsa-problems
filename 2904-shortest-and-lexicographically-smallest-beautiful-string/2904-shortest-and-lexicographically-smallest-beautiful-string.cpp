class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int l = 0, r = 0, oneCnt = 0;

        while (r < n) {
            if (s[r] == '1')
                oneCnt++;

            while (oneCnt == k){
                while(s[l] == '0') l++;

                string temp = s.substr(l, r-l+1);
                if(ans.empty() || temp.length() < ans.length() || (temp.length() == ans.length() && temp < ans)){
                    ans = temp;
                }

                oneCnt--;
                l++;
            }

            r++;
        }

        return ans;
    }
};