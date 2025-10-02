class Solution {
  public:
  int n;
  void solve(int sum,vector<vector<int>>&ans,int k,vector<int>&res,int prev)
  {
      if(k==0 && sum==n)
      {
          ans.push_back(res);return ;
      }
      if(k<=0 || sum>=n){
          return ;
      }
      for(int i=prev+1;i<=9;i++)
      {
          if(sum+i<=n)
          {
              res.push_back(i);
              solve(sum+i,ans,k-1,res,i);
              res.pop_back();
          }
      }
      return;
  }
    vector<vector<int>> combinationSum(int nn, int k) {
        // code here
        n=nn;
        vector<int>res;
        vector<vector<int>>ans;
        solve(0,ans,k,res,0);return ans;
    }
};