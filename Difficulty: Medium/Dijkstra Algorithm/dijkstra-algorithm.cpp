//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &e, int s) {
        // Code here
        vector<int>dp(n,INT_MAX);
        dp[s]=0;
        queue<pair<int,int>>q;
        q.push({s,0});
        vector<pair<int,int>>adj[n];
        for(int i=0;i<e.size();i++)
        {
            int x=e[i][0];
            int y=e[i][1];
            int z=e[i][2];
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }
        while(!q.empty())
        {
            auto p=q.front();
            int x=p.first;
            int y=p.second;
            q.pop();
            for(auto itr:adj[x])
            {
                if(y+itr.second<dp[itr.first])
                {
                   dp[itr.first]=itr.second+y; 
                   q.push({itr.first,dp[itr.first]});
                }
            }
        }
        return dp;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends