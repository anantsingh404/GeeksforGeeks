class Solution {
  public:
    vector<int> topoSort(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    // Build adjacency list and indegree count
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
        indeg[v]++;
    }

    // Kahn's algorithm (BFS)
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int nxt : adj[node]) {
            indeg[nxt]--;
            if (indeg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    

    return topo;
}
    int maxEdgesToAdd(int n, vector<vector<int>>& edges) {
        // code here
        vector<int> result = topoSort(n, edges);
        int sum=0;
        for(int i=0;i<n-1;i++)
        {
            sum+=n-1-i;
        }
        return sum-=edges.size();
        
    }
};
