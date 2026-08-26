class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>hash;
        for(string word : words){
            hash[word]++;
        }

        int length=0;
        bool midElement = false;
        for(auto [word, freq] : hash){
            if(freq == 0) continue;

            if(word[0] == word[1]){
                length += (freq/2)*4;
                if(freq%2 == 1) midElement = true;
            }

            else {
                string rev = word;
                swap(rev[0], rev[1]);
                if(hash.find(rev) != hash.end()){
                    int pairs = min(freq, hash[rev]);
                    length += pairs*4;
                    freq = 0;
                    hash[rev] = 0;
                }
            }
        }

        if (midElement) length += 2;
        return length;
    }
};