//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(int idx,vector<pair<int,int>>&vp,int sum,vector<vector<int>>&dp)
  {
      if(idx>=vp.size())
      {
          return 0;
      }
      if(dp[idx][sum]!=-1)
      {
          return dp[idx][sum];
      }
      int ans=0;
      if(vp[idx].first<=sum)
      {
          ans=max(ans,vp[idx].second+solve(idx+1,vp,sum-vp[idx].first,dp));
      }
      if(vp[idx].first<=sum){
      ans=max(ans,solve(idx+1,vp,sum,dp));
      }
      return dp[idx][sum]=ans;
      
  }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=val.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<wt.size();i++)
        {
            vp.push_back({wt[i],val[i]});
        }
        sort(vp.begin(),vp.end());
        int sum=accumulate(wt.begin(),wt.end(),0);
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(0,vp,W,dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends