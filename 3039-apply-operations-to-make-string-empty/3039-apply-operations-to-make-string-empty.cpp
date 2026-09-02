class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.length();
        vector<int> freq(26);
        unordered_map<char, int> lastOcc;

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
            lastOcc[s[i]] = i;
        }

        string ans = "";
        int maxFreq = *max_element(freq.begin(), freq.end());
        for(int i=0; i<n; i++){
            if(freq[s[i]-'a'] == maxFreq && i == lastOcc[s[i]]){
                ans += s[i];
            }
        }

        return ans;
    }
};