class Solution {
  public:
  int n;
    int solve(int i,int j,int turn,vector<vector<int>>&dp,vector<int>&arr)
    {
      if(i>j)
      {
          return 0;
      }
       if(i==j && turn==0)
        {
            return arr[i];
        }
        if(i==j)
        {
            return 0;
        }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      int ans=0;
      if(turn==0)
      {
          ans=max(arr[j]+solve(i,j-1,1,dp,arr),arr[i]+solve(i+1,j,1,dp,arr));
         
      }
      else
      {
          ans=min(solve(i,j-1,0,dp,arr),solve(i+1,j,0,dp,arr));
         
      }
      return dp[i][j]=ans;
    }
    int maximumAmount(vector<int> &arr) {
        // code here
        n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,0,dp,arr);
        
    }
};