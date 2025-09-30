class Solution {
  public:
  //set<vector<int>>ans;
  int n;vector<int>arr;
  void solve(set<vector<int>>&ans,vector<int>&temp,vector<int>&vis)
  {
      if(temp.size()==n)
      {
          ans.insert(temp);
          return;
      }
      for(int i=0;i<n;i++)
      {
          if(vis[i]==0)
          {
              vis[i]=1;
              temp.push_back(arr[i]);solve(ans,temp,vis);
              vis[i]=0;
              temp.pop_back();
          }
      }
      
  }
    vector<vector<int>> uniquePerms(vector<int>& a) {
        // code here
        arr=a;
        n=a.size();
       // sort(arr.begin(),arr.end());
        set<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(n,0);
        solve(ans,temp,vis);
        vector<vector<int>>res;
        for(auto itr:ans)
        {
            res.push_back(itr);
        }
        return res;
        
    }
};