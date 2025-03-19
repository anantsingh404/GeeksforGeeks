//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int idx,vector<int>&prices,int tc,int ts,vector<vector<vector<int>>>& dp,int n)
{
    if(idx==n || tc==0)
    {
        return 0;
    }
    if(dp[idx][ts][tc]!=-1)
    {
        return dp[idx][ts][tc];
    }
    int ans=0;
    if(ts==0)
    {
      ans=max(solve(idx+1,prices,tc,ts,dp,n),-1*prices[idx]+solve(idx+1,prices,tc,1,dp,n));
    }
    if(ts==1)
    {
      ans=max(solve(idx+1,prices,tc,1,dp,n),prices[idx]+solve(idx+1,prices,tc-1,0,dp,n));
    }
    return dp[idx][ts][tc]=ans;
}
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
      return solve(0,prices,k,0,dp,n);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends