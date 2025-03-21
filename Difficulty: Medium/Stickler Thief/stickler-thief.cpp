//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
  int n;
  int solve(int idx,vector<int>&arr,vector<int>&dp)
  {
    if(idx>=n)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int ans=0;
    ans=max(ans,arr[idx]+solve(idx+2,arr,dp));
      ans=max(ans,solve(idx+1,arr,dp));
      return dp[idx]=ans;
    
  }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,arr,dp);
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends