class Solution {
  public:
  vector<vector<int>>ans;
  int n;
  void solve(vector<int>&arr,vector<int>&vis,int count,vector<int>&dp)
  {
      if(count==n)
      {
          ans.push_back(dp);
          return;
      }
      for(int i=0;i<n;i++)
      {
          if(vis[i]==0)
      {
          vis[i]=1;
          dp.push_back(arr[i]);
          solve(arr,vis,count+1,dp);
          dp.pop_back();
          vis[i]=0;
      }
      }
      return;
  }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        ans.clear();
        n=arr.size();
        vector<int>dp;
        vector<int>vis(n,0);
        solve(arr,vis,0,dp);
        return ans;
        
    }
};