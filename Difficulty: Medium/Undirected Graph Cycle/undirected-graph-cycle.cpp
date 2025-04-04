//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int count=0;
   void dfs(int idx,vector<int>adj[],vector<bool>&vis,int parent)
  {
      vis[idx]=true;
      for(auto itr:adj[idx])
      {
          if(!vis[itr])
          {
              dfs(itr,adj,vis,idx);
          }
          else if(parent!=itr)
          {
              count++;
              break;
          }
      }
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
         vector<bool>vis(V,false);
         vector<int>adj[V];
         for(int i=-0;i<edges.size();i++)
         {
             int x=edges[i][0];
             int y=edges[i][1];
             adj[x].push_back(y);
             adj[y].push_back(x);
         }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,-1);
            }
        }
        return count>0;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends