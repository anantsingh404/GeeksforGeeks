//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int n;
  int solve(int idx,vector<int>&arr,int sum,vector<vector<int>>&dp)
  {
      if(idx>=n && sum==0)
      {
          return 1;
      }
      if(idx>=n || sum<0)
      {
          return 0;
      }
      if(dp[idx][sum]!=-1)
      {
          return dp[idx][sum];
      }
      int ans=0;
      if(sum-arr[idx]>=0)
      {
          ans=ans|solve(idx+1,arr,sum-arr[idx],dp);
      }
      ans=ans|solve(idx+1,arr,sum,dp);
      return dp[idx][sum]=ans;
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%2)
        {
            return false;
        }
        n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        solve(0,arr,sum/2,dp);
        for(int i=0;i<n;i++)
        {
            if(dp[i][sum/2]==1)
            {
                return true;
            }
        }
        return false;
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends