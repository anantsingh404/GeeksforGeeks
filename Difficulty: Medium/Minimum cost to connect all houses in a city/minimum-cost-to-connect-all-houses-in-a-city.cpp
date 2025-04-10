//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& a) {
        // code here
        int n=a.size();
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=a[i][0];
                int y1=a[i][1];
                int x2=a[j][0];
                int y2=a[j][1];
                int sum=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({sum,j});
                adj[j].push_back({sum,i});
                
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        vector<int>vis(n,0);
        int sum=0;
       while(!pq.empty())
       {
           auto x=pq.top();
           pq.pop();
           if(vis[x.second]==1)
           {
               continue;
           }
           sum+=x.first;
           vis[x.second]=1;
           for(auto itr:adj[x.second])
           {
               if(vis[itr.second]==0)
               {
                   pq.push(itr);
               }
           }
       }
       return sum;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends