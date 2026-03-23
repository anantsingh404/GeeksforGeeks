class Solution {

    int ans;

    void solve(int idx, ArrayList<Integer>[] adj, int[] vis, int count, int[] depth) {

        vis[idx] = 2;
        depth[idx] = count;

        for (int i = 0; i < adj[idx].size(); i++) {

            int x = adj[idx].get(i);

            if (vis[x] == 2) {
                ans = Math.max(ans, count - depth[x] + 1);
            }

            if (vis[x] == 0) {
                solve(x, adj, vis, count + 1, depth);
            }
        }

        vis[idx] = 1;
    }

    public int longestCycle(int V, int[][] edges) {

        ans = -1;
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] adj = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new ArrayList<>();
        }

        // build graph
        for (int i = 0; i < edges.length; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].add(y);
        }

        int[] vis = new int[V];
        int[] depth = new int[V];

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                solve(i, adj, vis, 0, depth);
            }
        }

        return ans;
    }
}