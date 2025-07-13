class Solution {
  public:
    bool check(int x) {
    if (x == 0) return false;
    while (x % 5 == 0) x /= 5;
    return x == 1;
}

int n;

int solve(int idx, string &s, vector<int> &dp) {
    if (idx == n) return 0;
    if (dp[idx] != -1) return dp[idx];

    int ans = 1e8;
    int temp = 0;

    for (int i = idx; i < n; i++) {
        temp = temp * 2 + (s[i] - '0');

        // skip if number has leading zeros (like "01", "001")
        if (s[idx] == '0' && i > idx) break;

        if (check(temp)) {
            int next = solve(i + 1, s, dp);
            if (next != 1e8) {
                ans = min(ans, 1 + next);
            }
        }
    }

    return dp[idx] = ans;
}

int cuts(string s) {
    n = s.size();
    vector<int> dp(n, -1);
    int ans = solve(0, s, dp);
    return (ans >= 1e8) ? -1 : ans;
}
};