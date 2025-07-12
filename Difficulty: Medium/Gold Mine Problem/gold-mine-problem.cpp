class Solution {
  public:
  int n,m;
  
  int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&mat)
  {
      if(i>=n || j>=m || i<0 || j<0)
      {
          return 0;
      }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      int ans=0;
      if(i-1>=0 && j+1<m )
      {
          ans=max(ans,solve(i-1,j+1,dp,mat));
      }
       if(i+1<n && j+1<m )
      {
          ans=max(ans,solve(i+1,j+1,dp,mat));
      }
       if(j+1<m)
      {
          ans=max(ans,solve(i,j+1,dp,mat));
      }
      
      return dp[i][j]=mat[i][j]+ans;
  }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++)
        {
           ans=max(ans,solve(i,0,dp,mat));
        }
        return ans;
    }
};