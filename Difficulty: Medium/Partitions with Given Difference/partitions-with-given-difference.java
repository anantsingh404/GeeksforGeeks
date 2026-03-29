class Solution {
    int n;
    int d;

    int solve(int idx, int[] arr, int[][] dp, int sum, int cur) {
        if (idx == n) 
        {
            int temp=sum-cur;
            if((temp-cur)==d)
            {
                return 1;
                
            }
            return 0;
        }

        if (dp[idx][cur] != -1) {
            return dp[idx][cur];
        }

        int take = solve(idx + 1, arr, dp, sum, cur + arr[idx]);
        int notTake = solve(idx + 1, arr, dp, sum, cur);

        return dp[idx][cur] = take + notTake;
    }

    public int countPartitions(int[] arr, int diff) {
        n = arr.length;
        d = diff;

        int sum = 0;
        int i = 0;
        while (i < n) {
            sum += arr[i];
            i++;
        }

        int[][] dp = new int[n][sum + 1];
        i = 0;
        while (i < n) {
            int j = 0;
            while (j <= sum) {
                dp[i][j] = -1;
                j++;
            }
            i++;
        }

        return solve(0, arr, dp, sum, 0);
    }
}