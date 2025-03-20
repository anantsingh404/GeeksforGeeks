//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  int n;
  int solve(int idx,vector<int>&pr,  vector<vector<vector<int>>>&dp,int comp,int count)
  {   
       
      if(idx==n || count==0)
      {
          return 0;
      }
      if(dp[idx][comp][count]!=-1)
      {
          return dp[idx][comp][count];
      }
      int ans;
      if(comp==0)
      {
          ans=max(-pr[idx]+solve(idx+1,pr,dp,1,count),solve(idx+1,pr,dp,0,count));
      }
      if(comp==1)
      {
          ans=max(solve(idx+1,pr,dp,1,count),pr[idx]+solve(idx+1,pr,dp,0,count-1));
      }
      return dp[idx][comp][count]=ans;
      
  }
    int maxProfit(vector<int> &pr) {
        // code here
        n=pr.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,pr,dp,0,2);
        
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends