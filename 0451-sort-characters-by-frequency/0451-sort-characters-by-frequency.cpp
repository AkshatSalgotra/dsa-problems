class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> cnt;

        for(char ch : s) cnt[ch]++;

        vector<pair<char, int>> freq(cnt.begin(), cnt.end());

        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        string ans = "";
        for(int i=0; i<freq.size(); i++){
            int currFreq = freq[i].second;
            while(currFreq){
                ans += freq[i].first;
                currFreq--;
            }
        }

        return ans;
    }
};