//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  set<string>st;
  void solve(string & s,vector<int>&vis,string &ans)
  {
      if(ans.size()==s.size())
      {   st.insert(ans);
          return;
      }
      for(int i=0;i<s.size();i++)
      {
          if(vis[i]==0)
          {
              vis[i]=1;
              ans.push_back(s[i]);
              solve(s,vis,ans);
              ans.pop_back();
              vis[i]=0;
          }
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        int n=s.size();
        vector<int>vis(n,0);
        string ans="";
        solve(s,vis,ans);
        vector<string>res;
        for(string x:st)
        {
            res.push_back(x);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends