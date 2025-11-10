class Solution {
  public:
  int n;
  int solve(int idx,int state,vector<int>&arr,vector<vector<int>>&dp)
  {
      if(idx>=n)
      {
          return 0;
      }
      if(dp[idx][state]!=-1)
      {
          return dp[idx][state];
          
      }
      int ans=0;
      if(state==1 && idx==n-1)
      {
          ans=solve(idx+2,0,arr,dp)+arr[idx];
      }
      else if(state==1)
      {
          ans=max(solve(idx+1,state,arr,dp),solve(idx+2,0,arr,dp)+arr[idx]);
      }
      else if(state==0)
      {
        ans=max(solve(idx+1,1,arr,dp)-arr[idx],solve(idx+1,state,arr,dp));  
      }
      return dp[idx][state]=ans;
  }
    int maxProfit(vector<int>& arr) {
        // code here
        n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,arr,dp);
        
    }
};