class Solution {
  public:
  vector<bool>vis;
  vector<bool>dp;
  bool solve(int node,vector<int> adj[])
  {
      if(dp[node])
      {
          return true;
          }
      if(vis[node])
      {
          return false;
      }
      vis[node]=true;
      bool ans=true;
      
      for(auto itr:adj[node])
      {
          ans=ans&solve(itr,adj);
      }
     
      return dp[node]=ans;
  }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
        }
        vis.assign(V,false);
    dp.assign(V,false);
      for(int i=0;i<V;i++)
      {  if(!vis[i]){
          solve(i,adj);
      }
      }
      vector<int>res;
      for(int i=0;i<V;i++)
      {
          if(dp[i])
          {
              res.push_back(i);
          }
      }
      return res;
        
    }
};