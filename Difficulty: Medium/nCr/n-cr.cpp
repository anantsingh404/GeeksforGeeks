//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  const int mod=1e9+7;
    int nCr(int n, int r) {
        // code here
          vector<vector<int>>dp(n+1,vector<int>(r+1,0));
        if(n<r)
        {
            return 0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=min(i,r);j++)
            {
                dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
            }
        }
        return dp[n][r];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends