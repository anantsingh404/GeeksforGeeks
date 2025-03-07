//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  int solve(int i,int j,vector<vector<int>>&dp,string &s)
  {
      if(i>j)
      {
          return 0;
      }
      if(i==j)
      {
          return 1;
      }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      int ans=0;
      if(s[i]==s[j])
      {
        ans=max(ans,2+solve(i+1,j-1,dp,s));  
      }
      
    ans=max(ans,max(solve(i+1,j,dp,s),solve(i,j-1,dp,s)));
    return dp[i][j]=ans;
  }
    int longestPalinSubseq(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,dp,s);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends