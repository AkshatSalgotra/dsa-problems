class Solution {
public:
    bool isValid(const string& s){
        int cnt=0;
        for(char ch : s){
            if(ch == '(') cnt++;
            else if(ch == ')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        if(s.empty()) return {""};

        unordered_set<string> vis;
        queue<string> q;

        q.push(s);
        vis.insert(s);
        bool found = false;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string curr = q.front();
                q.pop();

                if(isValid(curr)){
                    ans.push_back(curr);
                    found = true;
                }

                if(found) continue;

                for(int j=0; j<curr.length(); j++){
                    if(curr[j] != '(' && curr[j] != ')') continue;

                    string next = curr.substr(0, j) + curr.substr(j+1);
                    if(vis.find(next) == vis.end()){
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }

            if(found) break;
        }

        return ans;
    }
};