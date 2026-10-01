class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        queue<int> q;

        for(int i=0; i<n; i++){
            if(color[i] != 0) continue;

            q.push(i);
            color[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int nh : graph[node]){
                    if(color[nh] == 0){
                        color[nh] = -color[node];
                        q.push(nh);
                    } else if (color[nh] == color[node]) return false;
                }
            }
        }

        return true;
    }
};