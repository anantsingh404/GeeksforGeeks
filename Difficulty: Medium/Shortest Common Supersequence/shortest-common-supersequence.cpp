class Solution {
  public:
  int n,m;
  int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
  {
      if(i>=n || j>=m)
      {
          return 0;
      }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      int ans=0;
      if(s1[i]==s2[j])
      {
          ans=1+solve(i+1,j+1,s1,s2,dp);
      }
      else
      {
          ans=max(solve(i+1,j,s1,s2,dp),solve(i,j+1,s1,s2,dp));
      }
      return dp[i][j]=ans;
  }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        n=s1.size();
        m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return  n+m-solve(0,0,s1,s2,dp);
        
    }
};