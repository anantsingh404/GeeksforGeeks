//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
         stack<int>st;
        st.push(0);
        vector<int>vis(V,-1);
        vector<int>ans;
        while(!st.empty())
        {
          int temp=st.top();
          st.pop();
          if(vis[temp]==-1)
          {
              vis[temp]=1;
              ans.push_back(temp);
          }
          else
          {
              continue;
          }
          int n=adj[temp].size();
          for(int i=n-1;i>=0;i--)
          {
              if(vis[adj[temp][i]]==-1)
              {
                  st.push(adj[temp][i]);
              }
          }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends