class Solution {
  public:
  int n;
  int m;
  vector<vector<int>>dp;
  int solve(int i,int j,vector<vector<int>>&grid)
  {
      if(i==n-1 && j==m-1 && grid[i][j]==0)
      {
          return 1;
      }
      if(i<0 || i>=n || j<0 || j>=m)
      {
          return 0;
      }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      int sum=0;
      if(i+1<n && grid[i+1][j]==0){
      sum+=solve(i+1,j,grid);
      }
      if(j+1<m && grid[i][j+1]==0){
      sum+=solve(i,j+1,grid);
      }
      return dp[i][j]=sum;
  }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
       
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,grid);
    }
};