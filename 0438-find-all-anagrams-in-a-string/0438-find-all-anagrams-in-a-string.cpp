class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> ans;
        if(s.length() < p.length()) return ans;
        vector<int> pcnt(26), scnt(26);

        for(char ch : p){
            pcnt[ch-'a']++;
        }

        int wind = p.length();

        for(int i=0; i<n; i++){
            scnt[s[i]-'a']++;

            if(i >= wind){
                scnt[s[i-wind]-'a']--;
            }

            if(i >= wind-1){
                if(pcnt == scnt){
                    ans.push_back(i-wind+1);
                }
            }
        }

        return ans;
    }
};