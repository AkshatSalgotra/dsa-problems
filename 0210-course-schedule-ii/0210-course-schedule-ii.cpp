class Solution {
public:
    bool checkCycle(int src, vector<bool>& vis, vector<bool>& dfsVis, stack<int>& st, vector<int> adj[], vector<int>& topo){
        vis[src] = true;
        dfsVis[src] = true;

        for(auto nh : adj[src]){
            if(!vis[nh]){
                if(checkCycle(nh, vis, dfsVis, st, adj, topo)) return true;
            } else if (dfsVis[nh]) return true;
        }

        dfsVis[src] = false;
        st.push(src);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        vector<int> adj[n];

        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<bool> vis(n, false);
        vector<bool> dfsVis(n, false);
        stack<int> st;
        vector<int> topo;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(checkCycle(i, vis, dfsVis, st, adj, topo)) return {};   
            }
        }

        while(!st.empty()){
            int x = st.top();
            topo.push_back(x);
            st.pop();
        }

        return topo;
    }
};