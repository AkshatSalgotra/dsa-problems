class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        unordered_set<string> hash (begin(wordList), end(wordList));
        unordered_set<string> vis;

        int steps = 0;
        queue<string>q;
        q.push(beginWord);
        vis.insert(beginWord);
        while(!q.empty()){
            steps++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string curr = q.front();
                if(curr == endWord) return steps;
                q.pop();

                for(int j=0; j<n; j++){
                    string temp = curr;
                    for(int k=0; k < 26; k++){
                        temp[j] = 'a' + k;
                        if(hash.contains(temp) && !vis.contains(temp)){
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
        }

        return q.empty() ? 0 : steps;
    }
};