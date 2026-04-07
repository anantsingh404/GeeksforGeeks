class Solution {
    public int[] stableMarriage(int[][] men, int[][] women) {
        // code here
        int n = men.length;

    int[] wife = new int[n];      // wife[m] = w
    int[] husband = new int[n];   // husband[w] = m
    int[] next = new int[n];      // next woman to propose

    Arrays.fill(wife, -1);
    Arrays.fill(husband, -1);

    // Precompute women rankings
    int[][] womenRank = new int[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            womenRank[i][women[i][j]] = j;
        }
    }

    Queue<Integer> freeMen = new LinkedList<>();
    for (int i = 0; i < n; i++) {
        freeMen.add(i);
    }

    while (!freeMen.isEmpty()) {

        int m = freeMen.poll();
        int w = men[m][next[m]];
        next[m]++;

        if (husband[w] == -1) {
            // woman is free
            husband[w] = m;
            wife[m] = w;
        } else {
            int m2 = husband[w];

            // check preference
            if (womenRank[w][m] < womenRank[w][m2]) {
                // she prefers new man
                husband[w] = m;
                wife[m] = w;

                wife[m2] = -1;
                freeMen.add(m2);
            } else {
                // reject new man
                freeMen.add(m);
            }
        }
    }

    return wife;
    }
}