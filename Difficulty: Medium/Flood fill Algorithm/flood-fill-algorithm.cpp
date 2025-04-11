//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int col=0;
  int n,m;
  vector<vector<int>>vis;
 
  void solve(int i,int j,vector<vector<int>>&im,int nc)
  {   if(i>=n || i<0 || j>=m || j<0 || im[i][j]!=col || vis[i][j]==1)
  {
      return;
  }
      im[i][j]=nc;
      vis[i][j]=1;
      solve(i-1,j,im,nc);
        solve(i,j-1,im,nc);
          solve(i+1,j,im,nc);
            solve(i,j+1,im,nc);
             // solve(i-1,j+1,im,nc);
             //   solve(i-1,j-1,im,nc);
              //    solve(i+1,j+1,im,nc);
               //     solve(i+1,j-1,im,nc);
                    return;
      
  }
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc,
                                  int nc) {
        // Code here
        
       
        n=im.size();
        m=im[0].size();
         vis.assign(n,vector<int>(m,-1));
        col=im[sr][sc];
        solve(sr,sc,im,nc);
        return im;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends