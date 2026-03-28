import java.util.*;

class Solution {

    static int timer;
    static int[] tin, low, vis, mark;

    static void dfs(int node, int parent, ArrayList<ArrayList<Integer>> adj) {

        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child = 0;

        for (int it : adj.get(node)) {

            if (it == parent) {
                continue;
            }

            if (vis[it] == 0) {

                dfs(it, node, adj);

                low[node] = Math.min(low[node], low[it]);

                // articulation condition (non-root)
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }

                child++;
            } else {
                // back edge
                low[node] = Math.min(low[node], tin[it]);
            }
        }

        // root condition
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

    static ArrayList<Integer> articulationPoints(int V, int[][] edges) {

        // Step 1: Build adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        int i = 0;
        while (i < edges.length) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj.get(u).add(v);
            adj.get(v).add(u);

            i++;
        }

        // Step 2: Initialize arrays
        tin = new int[V];
        low = new int[V];
        vis = new int[V];
        mark = new int[V];
        timer = 0;

        // Step 3: DFS for all components
        int j = 0;
        while (j < V) {
            if (vis[j] == 0) {
                dfs(j, -1, adj);
            }
            j++;
        }

        // Step 4: Collect answer
        ArrayList<Integer> ans = new ArrayList<>();

        int k = 0;
        while (k < V) {
            if (mark[k] == 1) {
                ans.add(k);
            }
            k++;
        }

        if (ans.size() == 0) {
            ans.add(-1);
        }

        return ans;
    }
}