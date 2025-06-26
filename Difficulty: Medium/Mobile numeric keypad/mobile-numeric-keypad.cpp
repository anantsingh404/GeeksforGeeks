class Solution {
  public:
   int solve(int i, int j, vector<vector<int>>& dp, vector<vector<vector<int>>>& memo, int count) {
    if (i < 0 || i >= 4 || j < 0 || j >= 3 || dp[i][j] == -1)
    {
        return 0;
    }
    if (count == 0) {
        return 1;
    }
    if (memo[i][j][count] != -1) {
        return memo[i][j][count];
    }

    int ans = 0;
    ans += solve(i + 1, j, dp, memo, count - 1);
    ans += solve(i - 1, j, dp, memo, count - 1);
    ans += solve(i, j + 1, dp, memo, count - 1);
    ans += solve(i, j - 1, dp, memo, count - 1);
    ans+=solve(i,j,dp,memo,count-1);

    return memo[i][j][count] = ans;
}

int getCount(int n) {
    vector<vector<int>> dp(4, vector<int>(3, 0));
    dp[3][0] = -1;  // '*' position
    dp[3][2] = -1;  // '#' position

    vector<vector<vector<int>>> memo(4, vector<vector<int>>(3, vector<int>(n, -1)));

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (dp[i][j] != -1) {
               
                ans += solve(i, j, dp, memo, n - 1);
                // cout<<i<<' '<<j<<' '<<memo[i][j][n-1]<<endl;
            }
        }
    }
    return ans;
}

};