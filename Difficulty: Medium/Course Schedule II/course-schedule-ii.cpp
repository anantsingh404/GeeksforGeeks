class Solution {
  public:
  void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for (int nei : adj[node]) {
        if (!vis[nei]) {
            dfs(nei, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
  
    vector<int> findOrder(int n, vector<vector<int>> &g) {
        // code here
        vector<vector<int>>adj(n);
        for(int i=0;i<g.size();i++){
            int x=g[i][0];
            int y=g[i][1];
            adj[y].push_back(x);
            
        }
            return topoSort(n,adj);
            
    
        
       
        
    }
};