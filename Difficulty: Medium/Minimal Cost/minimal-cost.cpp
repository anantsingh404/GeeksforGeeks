//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int>dp;
  int t;
  int n;
  int solve(int idx,vector<int>&arr)
  {
      if(idx==n-1)
      {
          return 0;
      }
      if(dp[idx]!=-1)
      {
          return dp[idx];
      }
      int ans=1e6;
      for(int i=idx+1;i<=min(n-1,idx+t);i++)
      {
          ans=min(ans,abs(arr[idx]-arr[i])+solve(i,arr));
      }
      return dp[idx]=ans;
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        t=k;
        n=arr.size();
        dp.assign(n,-1);
        return solve(0,arr);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends