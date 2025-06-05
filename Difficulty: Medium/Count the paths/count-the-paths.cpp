class Solution {
  public:
  int d;
  vector<int>dp;
 
   int solve(int idx,vector<vector<int>>&adj)
   {
       if(idx==d)
       {
           return 1;
       }
       if(dp[idx]!=-1)
       {
           return dp[idx];
       }
       int ans=0;
       for(auto itr:adj[idx])
       {
           ans+=solve(itr,adj);
       }
       return dp[idx]=ans;
   }
  
    int countPaths(vector<vector<int>>& edges, int n, int src, int dest) {
        // Code here
        
        vector<vector<int>>adj(n);
        dp.assign(n,-1);
       // --src;
       // --dest;
        d=dest;
        
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
        }
        return solve(src,adj);
    }
};