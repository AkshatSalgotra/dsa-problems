class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int i = 0;
        int depth = 0;
        int score = 0;

        while(i < n){
            if(s[i] == '('){
                depth++;
                if(i < n-1 && s[i+1] == ')') score += 1 << (depth-1);
            }
            if(s[i] == ')') depth--;
            i++;
        }

        return score;
    }
};