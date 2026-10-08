class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int openCnt = 0;

        for(char ch : s){
            if(ch == '('){
                openCnt++;
                if(openCnt > 1){
                    ans += ch;
                }
            } else {
                if(openCnt > 1){
                    ans += ch;
                }
                openCnt--;
            }
        }

        return ans;
    }
};