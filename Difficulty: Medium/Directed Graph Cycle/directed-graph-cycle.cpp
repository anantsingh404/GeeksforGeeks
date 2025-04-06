//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool solve(int i,vector<int>adj[],vector<int>&vis)
  {   
      vis[i]=2;
       
      for(auto itr:adj[i])
      {
          if(vis[itr]==2)
          {
              return true;
          }
          else if(vis[itr]==0 && solve(itr,adj,vis))
          {
              return true;
          }
          
      }
      vis[i]=1;
      return false;
      
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>vis(V,0);
        vector<int>adj[V];
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
        }
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(solve(i,adj,vis))
                {
                    return true;
                }
            }
        }
        return false;
        
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends