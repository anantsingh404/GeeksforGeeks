//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int idx,vector<int>&dp,vector<int>&arr,int end)
  {
      if(idx>end)
      {
          return 0;
      }
      if(dp[idx]!=-1)
      {
          return dp[idx];
      }
      int ans=0;
      ans=max(solve(idx+1,dp,arr,end),arr[idx]+solve(idx+2,dp,arr,end));
      return dp[idx]=ans;
  }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);
        int ans=0;
        ans=max(solve(0,dp,arr,n-2),solve(1,dp1,arr,n-1));
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends