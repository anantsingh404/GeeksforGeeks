class Solution {
  public:
  int x,y;
  void solve(int idx,vector<vector<int>>&adj,vector<int>&vis)
  {
      
      ++x;
      y+=adj[idx].size();
      for(int itr:adj[idx])
      {
          if(itr!=idx && vis[itr]==0)
          {
               vis[itr]=1;
              solve(itr,adj,vis);
          }
         
      }
  }
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>vis(V,0);
        int extra=0;
        int comp=0;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
           {   
            //  cout<<i<<endl;
              vis[i]=1;
              ++comp;
              x=0;
              y=0;
              solve(i,adj,vis); 
              y/=2;
              extra+=(y-x+1);
             
           }
        } 
       // cout<<pq1.size()<<endl;
        int count=0;
        if(extra<comp-1)
        {
            return -1;
        }
        return comp-1;
    }
};
