//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int m;
  int solve(int n,vector<int>&dp)
  {
      if(n>m)
      {
          return 0;
      }
      if(n==m)
      {
          return 1;
      }
      if(dp[n]!=-1)
      {
          return dp[n];
      }
      return dp[n]=solve(n+1,dp)+solve(n+2,dp);
  }
    // Function to count number of ways to reach the nth stair.
    int countWays(int n) {
        m=n;
        // your code here
        vector<int>dp(n+1,-1);
        return solve(0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends