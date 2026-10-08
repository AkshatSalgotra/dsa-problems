class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& dfsVis){
        vis[src] = true;
        dfsVis[src] = true;

        for(auto nh : graph[src]){
            if(!vis[nh]){
                if(dfs(nh, graph, vis, dfsVis)) return true;
            } else if (dfsVis[nh]) return true;
        }

        dfsVis[src] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> dfsVis(n, false);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!dfs(i, graph, vis, dfsVis)) ans.push_back(i);
        }

        return ans;
    }
};