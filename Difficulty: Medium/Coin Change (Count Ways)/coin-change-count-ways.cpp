//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int n;
  int solve(int idx,vector<int>&coins,int sum,vector<vector<int>>&dp)
  {
     if(idx>=n)
      {
      return 0;
      }
      if(sum==0)
      {
          return 1;
      }
      if(dp[idx][sum]!=-1)
      {
          return dp[idx][sum];
      }
      
      int ans=0;
      if(coins[idx]<=sum)
      {
          ans=solve(idx,coins,sum-coins[idx],dp)+solve(idx+1,coins,sum,dp);
      }
      return dp[idx][sum]=ans;
  }
    int count(vector<int>& coins, int sum) {
        // code here.
        n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(0,coins,sum,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends