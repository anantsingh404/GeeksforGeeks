class Solution {
  public:
     const int mod=1e9+7;
    private:
    long long solve(int n,int k,vector<int>&dp)
    {
        //base case
        if(n==1) return k % mod;
        if(n==2) return (k*1LL*k) % mod;
        if(dp[n]!=-1) return dp[n];
        //conditions
        long long cnt1=solve(n-2,k,dp)*1LL*(k-1) % mod;
        long long cnt2=solve(n-1,k,dp)*1LL*(k-1) % mod;
        
        return dp[n]=(cnt1+cnt2)%mod;
    }
    public:
    long long countWays(int n, int k)
    {
        //memoized code
        vector<int>dp(n+1,-1);
        return solve(n,k,dp);
        
    }
};