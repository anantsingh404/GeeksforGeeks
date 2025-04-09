//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int> tin,vis,low,mark;
    int timer = 0;

    void findArticularPoint(int node,int parent,vector<int> adj[]){
        tin[node]=low[node]=timer;
        timer++;
        vis[node] =1;
        
        int child=0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                findArticularPoint(it,node,adj);
                low[node]=min(low[node],low[it]);
                
                if(low[it]>=tin[node] && parent != -1) 
                    mark[node]=1;
                
                child++;
            }
            else{
                low[node]=min(tin[it],low[node]);
            }
        }
        if(child>1 && parent==-1) mark[node]=1;
    }
   
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
         // Code here
         vector<int>adj[V];
         for(int i=0;i<edges.size();i++)
         {
             int x=edges[i][0];
             int y=edges[i][1];
             adj[x].push_back(y);
             adj[y].push_back(x);
         }
         tin.resize(V);
        vis.resize(V,0);
        low.resize(V);
        mark.resize(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                timer=0;
             findArticularPoint(i,-1,adj);
             
            }
        }
        vector<int> ans;
        for(int i=0; i<V; i++)
            if(mark[i]==1) ans.push_back(i);
            
        if(ans.size()==0) return {-1} ;
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends