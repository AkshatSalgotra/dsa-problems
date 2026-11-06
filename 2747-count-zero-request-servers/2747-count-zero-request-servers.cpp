class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        unordered_map<int, int> freq;
        int zero_count = n;
        int left = 0, right = 0;
        int num_logs = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int q_time = sorted_queries[i].first;
            int q_idx = sorted_queries[i].second;
            int start_time = q_time - x;
            
            while (right < num_logs && logs[right][1] <= q_time) {
                if (freq[logs[right][0]] == 0) {
                    zero_count--;
                }
                freq[logs[right][0]]++;
                right++;
            }
            
            while (left < num_logs && logs[left][1] < start_time) {
                freq[logs[left][0]]--;
                if (freq[logs[left][0]] == 0) {
                    zero_count++;
                }
                left++;
            }
            
            ans[q_idx] = zero_count;
        }
        
        return ans;
    }
};