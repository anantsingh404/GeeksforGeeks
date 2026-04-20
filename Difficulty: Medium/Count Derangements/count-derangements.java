class Solution {
    public int derangeCount(int n) {
        // code here
          if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 0;
        }

        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 0;

        int i = 2;
        while (i <= n) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
            i++;
        }

        return dp[n];
    }
};