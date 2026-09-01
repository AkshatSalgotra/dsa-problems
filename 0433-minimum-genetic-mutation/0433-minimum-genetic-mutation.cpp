class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = startGene.length();
        unordered_set<string> hash (bank.begin(), bank.end());
        vector<char> ch = {'A', 'C', 'G', 'T'};

        int mutations = 0;
        queue<string>q;
        q.push(startGene);
        hash.erase(startGene);
        while(!q.empty()){
            mutations++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string curr = q.front();
                if(curr == endGene) return mutations-1;
                q.pop();

                for(int j=0; j<n; j++){
                    string temp = curr;
                    for(int k=0; k < ch.size(); k++){
                        temp[j] = ch[k];
                        if(hash.find(temp) != hash.end()){
                            q.push(temp);
                            hash.erase(temp);
                        }
                    }
                }
            }
        }

        return -1;
    }
};