//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int n;
  int solve(int idx,vector<vector<int>>&dp,vector<int>&coins,int sum)
  {
      if(idx>=n && sum==0)
      {
          return 0;
      }
      if(sum==0)
      {
          return 0;
      }
      if(sum<0)
      {
          return 1e8;
      }
      if(idx>=n)
      {
          return 1e8;
      }
      if(dp[idx][sum]!=-1)
      {
          return dp[idx][sum];
      }
      int ans=1e8;
      ans=min(ans,1+solve(idx,dp,coins,sum-coins[idx]));
      ans=min(ans,solve(idx+1,dp,coins,sum));
      return dp[idx][sum]=ans;
      
  }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        sort(coins.rbegin(),coins.rend());
        n=coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int x=solve(0,dp,coins,sum);
        if(x<1e8)
        {
          return x;  
        }
        return -1;
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
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends