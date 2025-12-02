class Solution {
  public:
  vector<vector<int>>cs;
  int n;
  int solve(int idx,int mask,vector<vector<int>>&dp)
  {
      if(mask==(1<<n)-1)
      {
          return cs[idx][0];
      }
      if(dp[idx][mask]!=-1)
      {
          return dp[idx][mask];
      }
      int ans=INT_MAX;
      for(int i=0;i<n;i++)
      {
          if(((1<<i)&mask)==0)
          {
              ans=min(ans,cs[idx][i]+solve(i,mask|(1<<i),dp));
          }
      }
      return dp[idx][mask]=ans;
  }
    int tsp(vector<vector<int>>& cost) {
        // code here
        cs.clear();
        cs=cost;
        n=cost.size();
        vector<vector<int>>dp(16,vector<int>((1<<n),-1));
        return solve(0,1,dp);
        
    }
};