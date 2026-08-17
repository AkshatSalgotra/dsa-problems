class Solution {
public:

    void dfs(int node, vector<bool>& vis, vector<int> adj[]){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vis, adj);
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<bool> vis(n+1, false);
        int cnt=0;
        for(int i=1; i<n+1; i++){
            if(vis[i] == false){
                dfs(i, vis, adj);
                cnt++;
            }
        }

        return cnt;
    }
};