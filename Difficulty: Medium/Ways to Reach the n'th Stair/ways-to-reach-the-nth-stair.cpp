//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int>dp;
  int solve(int n)
  {
      if(n==0)
      {
          return 1;
      }
      if(n<0)
      {
          return 0;
      }
      if(dp[n]!=-1)
      {
          return dp[n];
      }
      return dp[n]=solve(n-1)+solve(n-2);
  }
    int countWays(int n) {
        // your code here
        dp.assign(n+1,-1);
        return solve(n);
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