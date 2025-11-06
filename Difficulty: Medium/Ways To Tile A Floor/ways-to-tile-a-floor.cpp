class Solution {
  public:
  int solve(int n,vector<int>&dp){
     if(n==0){
         return 1;
     }if(n<0)
     {
         return 0;
     }
     if(dp[n]!=-1){
         return dp[n];
     }
     int ans=0;
     if(n>=2)
     {
        ans+=solve(n-2,dp); 
     }
     ans+=solve(n-1,dp);
     return dp[n]=ans;
  }
    int numberOfWays(int n) {
        // code here
vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};