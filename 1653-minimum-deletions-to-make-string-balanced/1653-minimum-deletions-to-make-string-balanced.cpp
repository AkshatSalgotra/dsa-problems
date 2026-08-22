class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int cnt=0;
        stack<char> st;

        for(char ch : s){
            if(!st.empty() && st.top() == 'b' && ch == 'a'){
                st.pop();
                cnt++;
            } else {
                st.push(ch);
            }
        }

        return cnt;
    }
};