class Solution {

    boolean check(int idx, ArrayList<Integer>[] adj, int[] vis) {
        vis[idx] = 2;

        int i = 0;
        while (i < adj[idx].size()) {
            int x = adj[idx].get(i);

            if (vis[x] == 2) {
                return true;
            }

            if (vis[x] == 0) {
                if (check(x, adj, vis)) {
                    return true;
                }
            }

            i++;
        }

        vis[idx] = 1;
        return false;
    }

    public boolean canFinish(int n, int[][] pre) {
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] adj = new ArrayList[n];

        int i = 0;
        while (i < n) {
            adj[i] = new ArrayList<>();
            i++;
        }

        i = 0;
        while (i < pre.length) {
            int x = pre[i][0];
            int y = pre[i][1];
            adj[y].add(x);
            i++;
        }

        int[] vis = new int[n];

        i = 0;
        while (i < n) {
            vis[i] = 0;
            i++;
        }

        i = 0;
        while (i < n) {
            if (vis[i] == 0) {
                if (check(i, adj, vis)) {
                    return false;
                }
            }
            i++;
        }

        return true;
    }
}