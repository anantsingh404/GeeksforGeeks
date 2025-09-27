class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int  n = arr.size();
    int ans = 0;
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            dp[i] += dp[i - 1]; // prefix sum carry
        }

        int bit = arr[i] ^ (dp[i] % 2); // effective bit after flips

        if (bit == 0) { // need flip
            if (i + k > n) return -1;
            ans++;
            dp[i]++;      // start flip
            dp[i + k]--;  // end flip
        }
    }

    return ans;
    }
};