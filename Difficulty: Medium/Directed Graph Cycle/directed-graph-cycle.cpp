class Solution {
  public:
  bool check(int idx,vector<vector<int>>&adj,vector<int>&vis)
  {
      vis[idx]=2;
      for(auto itr:adj[idx])
      {
          if(vis[itr]==2)
          {
            return true;  
          }
          if(check(itr,adj,vis))
          {
              return true;
          }
         
      }
     
      vis[idx]=1;
       return false;
  }
    bool isCyclic(int n, vector<vector<int>> &edge) {
        // code here
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edge.size();i++)
        {
            int x=edge[i][0];
            int y=edge[i][1];
            adj[x].push_back(y);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(check(i,adj,vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};