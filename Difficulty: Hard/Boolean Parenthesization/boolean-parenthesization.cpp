//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  
int solve(string &s,int i,int j,vector<vector<vector<int>>>&dp,int istrue)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j][istrue]!=-1)
    {
        return dp[i][j][istrue];
    }
    if(i==j)
    {
       if(istrue)
       {
           if(s[i]=='T')
           {
               return 1;
               
           }
           else
           {
               return 0;
           }
       }
       else
       {
           if(s[i]=='F')
           {
               return 1;
           }
           else
           {
               return 0;
           }
       }
    }
    int count=0;
    for(int idx=i+1;idx<j;idx+=2)
    {
        int lt=solve(s,i,idx-1,dp,1);
        int lf=solve(s,i,idx-1,dp,0);
        int rt=solve(s,idx+1,j,dp,1);
        int rf=solve(s,idx+1,j,dp,0);
        if(s[idx]=='|')
        {   
            if(istrue)
            {
            count=(count+(lt*rf) +(lf*rt)+(lt*rt));
            
             }
            else
            {
            count=(count+(lf*rf));
            }
        }
        if(s[idx]=='&')
        {
            if(istrue)
            {
              count=(count+(lt*rt));  
            }
            else
            {
                count=(count+(lf*rt)+(lt*rf)+(lf*rf));
            }
        }
        if(s[idx]=='^')
        {
            if(istrue)
            {
                count=(count+(lf*rt)+(rf*lt));
            }
            else
            {
                count=(count+(lt*rt)+(lf*rf));
            }
        }
        }
        return dp[i][j][istrue]=count;
    }
    int countWays(string &s) {
        // code here
        int n=s.size();
          vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(3,-1)));
        return solve(s,0,n-1,dp,1);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends