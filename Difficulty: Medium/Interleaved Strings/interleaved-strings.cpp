class Solution {
  public:
  int n,m,l;
  int solve(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<int>>&dp)
  {
      if(k>=l)
      {
          return 1;
      }
      if(i>=n && j>=m)
      {
          return 0;
      }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      int ans=0;
      if(i<n && s1[i]==s3[k])
      {
          ans=ans|solve(i+1,j,k+1,s1,s2,s3,dp);
      }
      if(j<m && s2[j]==s3[k])
      {
          ans=ans|solve(i,j+1,k+1,s1,s2,s3,dp);
      }
      return dp[i][j]=ans;
  }
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        n=s1.size();
        m=s2.size();
        l=s3.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,0,s1,s2,s3,dp);
        
    }
};