class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
         int n= s.size();
        vector<long long> dp(n,0);
        dp[0] = s[0]-'0';
        long long ans = dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i] = dp[i-1]*10 + (s[i]-'0')*(i+1);
            ans = ans + dp[i];
        }
        return ans;
        
    }
};