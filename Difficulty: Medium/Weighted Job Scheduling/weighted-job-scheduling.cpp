class Solution {
  public:
  int solve(int idx,vector<vector<int>>&arr,vector<int>&dp){
      if(idx==dp.size()){
          return 0;
      }
      if(dp[idx]!=-1)
      {
          return dp[idx];
      }
      
      int take=0,nt=0;
       int x = lower_bound(
        arr.begin() + idx + 1,
        arr.end(),
        vector<int>{arr[idx][1], 0, 0},
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        }
    ) - arr.begin();
      take+=arr[idx][2];
      take+=solve(x,arr,dp);
      nt+=solve(idx+1,arr,dp);
      return dp[idx]=max(take,nt);
  }
    int maxProfit(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());vector<int>dp(n,-1);
        return solve(0,arr,dp);
    }
};
