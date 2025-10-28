class Solution {
  public:
  int ans;
  void solve(int idx, vector<vector<int>>&adj,vector<int>&vis,int & dis,int & node,int cur)
  {
      vis[idx]=1;
      if(cur>dis)
      {
          dis=cur;
          node=idx;
          ans=dis;
      }
      for(int i=0;i<adj[idx].size();i++)
      {
          int x=adj[idx][i];
          if(vis[x]==0)
          {
              solve(x,adj,vis,dis,node,cur+1);
          }
      }
      return;
  }
    int diameter(int V, vector<vector<int>>& e) {
        // Code here
        vector<vector<int>>adj(V);
        ans=0;
        for(int i=0;i<e.size();i++)
        {
            int x=e[i][0];
            int y=e[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            
        }
        int dis=0;
        int cur=0;
        int node=0;
        vector<int>vis(V,0);
        solve(0,adj,vis,dis,node,cur);
        vis.assign(V,0);
        dis=0;
        cur=0;
        solve(node,adj,vis,dis,node,cur);
        return ans;
        
        
        
    }
};
