//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int n;
  int m;
  void dfs(int i,int j,vector<vector<char>>&grid)
  {
      if(i>=n || i<0 || j<0 || j>=m ||grid[i][j]=='0')
      {
          return ;
      }
      grid[i][j]='0';
      dfs(i-1,j,grid);
      dfs(i,j-1,grid);
      dfs(i+1,j,grid);
      dfs(i,j+1,grid);
       dfs(i-1,j+1,grid);
      dfs(i+1,j-1,grid);
      dfs(i+1,j+1,grid);
      dfs(i-1,j-1,grid);
      
      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!='0')
                {
                    ++count;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends