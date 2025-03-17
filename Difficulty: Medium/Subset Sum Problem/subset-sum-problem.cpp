//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int n;
  int solve(int idx,vector<int>&arr,vector<vector<int>>&dp,int sum)
  {
      if(idx>=n && sum==0)
      {
          return 1;
      }
      if(idx>=n)
      {
          return 0;
      }
      if(sum<0)
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
      ans=ans|solve(idx+1,arr,dp,sum-arr[idx]); 
      ans=ans|solve(idx+1,arr,dp,sum);
      return dp[idx][sum]=ans;
      
      
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        solve(0,arr,dp,sum);
        for(int i=0;i<n;i++)
        {
            if(dp[i][sum]==1)
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends