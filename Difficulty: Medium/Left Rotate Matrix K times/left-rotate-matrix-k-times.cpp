//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        
        int n=mat[0].size();
        k=k%n;
        int m=mat.size();
        if(k==0)
        {
            return mat;
        }
        vector<vector<int>>dp;
        for(int i=0;i<m;i++)
        {   vector<int>ans;
            for(int j=k;j<n;j++)
            {
                ans.push_back(mat[i][j]);
            }
            for(int j=0;j<k;j++)
            {
                ans.push_back(mat[i][j]);
            }
            dp.push_back(ans);
        }
        
        return dp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends