class Solution {
public:
    void getParenthesis(vector<string> &ans, string currEl, int openCnt, int closeCnt, int n){
        if(openCnt == n && closeCnt == n){
            ans.push_back(currEl);
            return;
        }
        if(openCnt < n){
            currEl.push_back('(');
            getParenthesis(ans, currEl, openCnt+1, closeCnt, n);
            currEl.pop_back();
        }
        if(closeCnt < openCnt){
            currEl.push_back(')');
            getParenthesis(ans, currEl, openCnt, closeCnt+1, n);
            currEl.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string currEl = "";
        vector<string> ans;
        int openCnt = 0;
        int closeCnt = 0;

        getParenthesis(ans, currEl, openCnt, closeCnt, n);
        return ans;
    }
};