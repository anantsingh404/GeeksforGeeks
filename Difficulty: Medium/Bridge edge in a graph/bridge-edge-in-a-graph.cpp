//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  void solve(int i,vector<int>adj[],vector<int>&vis)
  {
      vis[i]=1;
      for(auto itr:adj[i])
      {
          if(vis[itr]==0)
          {
              solve(itr,adj,vis);
          }
      }
      return;
  }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
    vector<int>adj[V];
    bool temp=false;
    for(int i=0;i<edges.size();i++)
    {
        int x=edges[i][0];
        int y=edges[i][1];
    pair<int,int>p,q,r;
    p={x,y};
    q={y,x};
    r={c,d};
        if(p!=r && q!=r)
        {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        else
        {
            temp=true;
        }
    }
    int count=0;
    vector<int>vis(V,0);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
          ++count;
          solve(i,adj,vis);  
        }
    }
    int sum=0;
    if(!temp)
    {
        return false;
    }
    adj[c].push_back(d);
    adj[d].push_back(c);
    vis.assign(V,0);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
          ++sum;
          solve(i,adj,vis);  
        }
    }
   // cout<<count<<" "<<sum<<endl;
    return count>sum;
    
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends