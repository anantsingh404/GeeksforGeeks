class Solution {
  public:
  
  int solve(int n,vector<int>&dp)
  {
      if(n==0)
      {
          return 0;
      }
      if(n<0)
      {
          return 1e5;
      }
       if(dp[n]!=-1)
       {
           return dp[n];
       };
       int ans=1e5;
       for(int i=1;i<=sqrt(n);i++)
       {
           if(n-i*i>=0)
           {
               ans=min(ans,1+solve(n-i*i,dp));
           }
       }return dp[n]=ans;
  }
    int minSquares(int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};