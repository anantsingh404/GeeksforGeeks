//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
  int n;
  int solve(int idx,vector<int>&cost,vector<int>&dp)
  {
    if(idx>=n)
    {
        return 0;
    }
    if(idx)
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }

    return dp[idx]=cost[idx]+min(solve(idx+1,cost,dp),solve(idx+2,cost,dp));
  }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        n=cost.size();
        vector<int>dp(n+1,-1);
         vector<int>dp1(n+1,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp1));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends