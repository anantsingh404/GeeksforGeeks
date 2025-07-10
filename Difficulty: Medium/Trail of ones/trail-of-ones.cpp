class Solution {
  public:
  int solve(int n,int parity,vector<vector<int>>&dp)
  {
      if(n==0)
      {
          return 1;
      }
      if(dp[n][parity]!=-1)
      {
          return dp[n][parity];
      }
      int sum=0;
      if(parity==0)
      {
          sum+=solve(n-1,0,dp);
          sum+=solve(n-1,1,dp);
      }
      if(parity==1)
      {
          sum+=solve(n-1,0,dp);
      }
     
      return dp[n][parity]=sum;
  
  }
    int countConsec(int n)
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int x=solve(n,0,dp);
        int y=solve(n,1,dp);
        return pow(2,n)-(x);
    }
};