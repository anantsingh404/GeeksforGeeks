//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int n,m;
  vector<vector<int>>dp1;
  int solve(int i,int j,string &s1,string &s2)
  {
    
      if(j==m)
      {
          return n-i;
      }
      if(i==n)
      {
          return m-j;
      }
      if(dp1[i][j]!=-1)
      {
          return dp1[i][j];
      }
      int ans=INT_MAX;
      if(s1[i]==s2[j])
      {
          ans=min(ans,solve(i+1,j+1,s1,s2));
      }
      else
      {
          ans=min(ans,1+solve(i+1,j,s1,s2));
          ans=min(ans,1+solve(i,j+1,s1,s2));
          ans=min(ans,1+solve(i+1,j+1,s1,s2));
      }
      return dp1[i][j]=ans;
  }
    int editDistance(string str1, string str2) {
        // Code here
        n=str1.size();
        m=str2.size();
        dp1.assign(n,vector<int>(m,-1));
        return solve(0,0,str1,str2);
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends