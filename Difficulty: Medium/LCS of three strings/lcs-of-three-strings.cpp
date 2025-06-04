class Solution {
  public:
  int n,m,l;
  vector<vector<vector<int>>>dp;
  int solve(int i,int j,int k,string &s1,string &s2,string &s3)
  {
      if(i>=n || j>=m || k>=l)
      {
          return 0;
      }
      if(dp[i][j][k]!=-1)
      {
          return dp[i][j][k];
      }
      int ans=0;
      if(s1[i]==s2[j] && s2[j]==s3[k])
      {
          ans=1+solve(i+1,j+1,k+1,s1,s2,s3);
      }
      else
      {
          ans=max(ans,solve(i+1,j,k,s1,s2,s3));
           ans=max(ans,solve(i,j+1,k,s1,s2,s3));
            ans=max(ans,solve(i,j,k+1,s1,s2,s3));
             ans=max(ans,solve(i+1,j+1,k,s1,s2,s3));
              ans=max(ans,solve(i+1,j,k+1,s1,s2,s3));
               ans=max(ans,solve(i,j+1,k+1,s1,s2,s3));
                ans=max(ans,solve(i+1,j+1,k+1,s1,s2,s3));
      }
      
      return dp[i][j][k]=ans;
  }
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Code here
         n=s1.size();
        m=s2.size();
        l=s3.size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(l,-1)));
        return solve(0,0,0,s1,s2,s3);
    }
};
